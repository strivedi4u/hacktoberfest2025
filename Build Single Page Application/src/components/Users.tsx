import { useEffect, useState } from "react";
import axios from "axios";
import { Users as UsersIcon } from "lucide-react";

// TypeScript interface for User
interface User {
  id: number;
  name: string;
  email: string;
  username: string;
}

const Users: React.FC = () => {
  const [users, setUsers] = useState<User[]>([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);

  useEffect(() => {
    axios
      .get<User[]>("https://jsonplaceholder.typicode.com/users?_limit=6")
      .then((response) => setUsers(response.data))
      .catch(() => setError("Error fetching users"))
      .finally(() => setLoading(false));
  }, []);

  if (loading) return <p className="text-center text-gray-600">Loading users...</p>;
  if (error) return <p className="text-center text-red-500">{error}</p>;

  return (
    <div className="grid md:grid-cols-3 gap-6 mt-6">
      {users.map((user) => (
        <div
          key={user.id}
          className="bg-white p-6 rounded-xl shadow-xl hover:shadow-2xl transition-transform transform hover:-translate-y-2"
        >
          <div className="w-12 h-12 bg-gradient-to-r from-purple-600 to-pink-400 rounded-full flex items-center justify-center mb-4 mx-auto">
            <UsersIcon className="text-white" size={20} />
          </div>
          <h3 className="text-lg font-bold text-center mb-1">{user.name}</h3>
          <p className="text-gray-600 text-center">@{user.username}</p>
          <p className="text-gray-500 text-center mt-1">{user.email}</p>
        </div>
      ))}
    </div>
  );
};

export default Users;
