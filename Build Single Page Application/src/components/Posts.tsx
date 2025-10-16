
import { useEffect, useState } from "react";
import axios from "axios";
import { FileText } from "lucide-react";

// TypeScript interface for Post
interface Post {
  id: number;
  title: string;
  body: string;
}

const Posts: React.FC = () => {
  const [posts, setPosts] = useState<Post[]>([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);

  useEffect(() => {
    axios
      .get<Post[]>("https://jsonplaceholder.typicode.com/posts?_limit=6")
      .then((response) => setPosts(response.data))
      .catch(() => setError("Error fetching posts"))
      .finally(() => setLoading(false));
  }, []);

  if (loading) return <p className="text-center text-gray-600">Loading posts...</p>;
  if (error) return <p className="text-center text-red-500">{error}</p>;

  return (
    <div className="grid md:grid-cols-3 gap-6 mt-6">
      {posts.map((post) => (
        <div
          key={post.id}
          className="bg-white p-6 rounded-xl shadow-xl hover:shadow-2xl transition-transform transform hover:-translate-y-2"
        >
          <div className="w-12 h-12 bg-gradient-to-r from-purple-600 to-pink-400 rounded-full flex items-center justify-center mb-4 mx-auto">
            <FileText className="text-white" size={20} />
          </div>
          <h3 className="text-lg font-bold mb-2 text-center">{post.title}</h3>
          <p className="text-gray-600 text-center">{post.body}</p>
        </div>
      ))}
    </div>
  );
};

export default Posts;
