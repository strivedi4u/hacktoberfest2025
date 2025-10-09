# 🌐 GitHub CodeSource App (MERN Stack)

A simple MERN application that lets users search for GitHub profiles, view repositories, and explore trending repositories by language — all using the **GitHub REST API**.

This project is part of the [Hacktoberfest 2025](https://hacktoberfest.com/) open source contributions under the **strivedi4u/hacktoberfest2025** repository.

---

## 🚀 Features
- 🔍 Search for any GitHub user by username  
- 📂 View user profile and public repositories  
- 🌟 Explore popular repositories by language  
- 🎨 Built with React + Vite frontend and Express.js backend  
- 🧩 Designed for easy contribution and extension

---

## 🏗️ Tech Stack
| Layer | Technology |
|--------|-------------|
| Frontend | React + Vite |
| Backend | Express.js |
| Database | MongoDB (planned) |
| API | GitHub REST API |
| Tools | Node.js, dotenv, CORS, nodemon |

---

## ⚙️ Project Setup


```bash
1️⃣ Clone the Repository
git clone https://github.com/strivedi4u/hacktoberfest2025.git
cd hacktoberfest2025/MERN-Projects/github-codesource-app

2️⃣ Setup the Backend
cd backend
npm install

### Create Environment File
Copy the example file:

cp .env.example .env
Then open .env and set your GitHub token:

PORT=5000
GITHUB_API_KEY=your_personal_github_token_here

### Start the Backend
npm run dev

3️⃣ Setup the Frontend
cd ../frontend
npm install

### Start the Frontend
npm run dev
### (Default port: 3000)


🧩 Folder Structure
github-codesource-app/
├── backend/             # Express.js API server
│   ├── controllers/
│   ├── routes/
│   ├── server.js
│   └── .env.example
├── frontend/            # React + Vite UI
│   ├── src/
│   ├── package.json
│   └── vite.config.js
└── README.md            # Project documentation

```


## 🧑‍💻 Contributing

Contributions are welcome!
If you’re participating in Hacktoberfest 2025, here’s how to help:

```
Fork this repository

Create a new branch:

git checkout -b add-env-example-docs

Commit your changes:

git commit -m "docs: add README and .env.example for Github CodeSource App"


Push your branch:

git push origin add-env-example-docs


Open a Pull Request 🎉

```




