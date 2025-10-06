import React, { useState } from "react";
import "./App.css";

function App() {
  const [expenses, setExpenses] = useState([]);
  const [description, setDescription] = useState("");
  const [amount, setAmount] = useState("");
  const [category, setCategory] = useState("");
  const [editId, setEditId] = useState(null);

  // Add new expense
  const addExpense = () => {
    if (editId !== null) {
      const updatedExpenses = expenses.map((expense) =>
        expense.id === editId
          ? { ...expense, description, amount, category }
          : expense
      );
      setExpenses(updatedExpenses);
      setEditId(null);
    } else {
      const newExpense = {
        id: Date.now(),
        description,
        amount: parseFloat(amount),
        category,
      };
      setExpenses([...expenses, newExpense]);
    }
    resetFields();
  };

  // Delete expense
  const deleteExpense = (id) => {
    setExpenses(expenses.filter((expense) => expense.id !== id));
  };

  // Edit expense
  const editExpense = (id) => {
    const expense = expenses.find((expense) => expense.id === id);
    setDescription(expense.description);
    setAmount(expense.amount);
    setCategory(expense.category);
    setEditId(id);
  };

  // Reset input fields
  const resetFields = () => {
    setDescription("");
    setAmount("");
    setCategory("");
  };

  // Calculate total expenses
  const totalExpenses = expenses.reduce((acc, expense) => acc + expense.amount, 0);

  return (
    <div className="App">
      <h1>Expense Tracker</h1>

      <div className="form">
        <input
          type="text"
          placeholder="Description"
          value={description}
          onChange={(e) => setDescription(e.target.value)}
        />
        <input
          type="number"
          placeholder="Amount"
          value={amount}
          onChange={(e) => setAmount(e.target.value)}
        />
        <input
          type="text"
          placeholder="Category"
          value={category}
          onChange={(e) => setCategory(e.target.value)}
        />
        <button onClick={addExpense}>
          {editId !== null ? "Update Expense" : "Add Expense"}
        </button>
      </div>

      <div className="expense-list">
        <h2>Your Expenses</h2>
        {expenses.length === 0 ? (
          <p>No expenses added yet</p>
        ) : (
          <ul>
            {expenses.map((expense) => (
              <li key={expense.id}>
                <strong>{expense.description}</strong> - ${expense.amount} -{" "}
                {expense.category}
                <button onClick={() => editExpense(expense.id)}>Edit</button>
                <button onClick={() => deleteExpense(expense.id)}>Delete</button>
              </li>
            ))}
          </ul>
        )}
      </div>

      <div className="summary">
        <h2>Total Expenses: ${totalExpenses.toFixed(2)}</h2>
      </div>
    </div>
  );
}

export default App;
