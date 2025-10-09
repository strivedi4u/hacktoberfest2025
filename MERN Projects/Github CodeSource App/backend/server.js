import express from "express";
import dotenv from "dotenv";
import cors from "cors";

import userRoutes from "./routes/user.route.js";
import exploreRoutes from "./routes/explore.route.js";

// dotenv.config();
dotenv.config({ path: './backend/.env' });

const app = express();

app.use(cors());

// ✅ Use PORT from .env or default to 5000

const PORT = process.env.PORT || 5000;


app.get("/", (req, res) => {
  res.send("Server is ready");
});

app.use("/api/users", userRoutes);
app.use("/api/explore", exploreRoutes);

app.listen(PORT, () => {
  console.log("Server started on http://localhost:5000");
});
