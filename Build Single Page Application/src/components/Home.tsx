import React, { useEffect, useState } from 'react';
import { Home as HomeIcon, FileText, Users as UsersIcon } from 'lucide-react';

// Types
interface Post {
  id: number;
  title: string;
  body: string;
}

interface User {
  id: number;
  name: string;
  email: string;
  username: string;
  phone: string;
  website: string;
}

const Home: React.FC = () => {
  // State
  const [posts, setPosts] = useState<Post[]>([]);
  const [users, setUsers] = useState<User[]>([]);
  const [loadingPosts, setLoadingPosts] = useState(true);
  const [loadingUsers, setLoadingUsers] = useState(true);

  // Fetch posts
  useEffect(() => {
    fetch('https://jsonplaceholder.typicode.com/posts?_limit=5')
      .then((res) => res.json())
      .then((data: Post[]) => {
        setPosts(data);
        setLoadingPosts(false);
      })
      .catch((err) => console.error(err));
  }, []);

  // Fetch users
  useEffect(() => {
    fetch('https://jsonplaceholder.typicode.com/users?_limit=5')
      .then((res) => res.json())
      .then((data: User[]) => {
        setUsers(data);
        setLoadingUsers(false);
      })
      .catch((err) => console.error(err));
  }, []);

  return (
    <div className="container mx-auto px-4 py-8">
      <div className="text-center space-y-4">
        <h1 className="text-3xl font-bold bg-gradient-to-r from-purple-500 to-pink-400 bg-clip-text text-transparent">
          Welcome to MYpost
        </h1>
        <p className="text-lg text-gray-600">
          Create Posts and find your users!
        </p>
      </div>

      {/* Posts Section */}
      <h2 className="text-2xl font-bold mt-12 mb-4">Latest Posts</h2>
      <div className="grid md:grid-cols-3 gap-6">
        {loadingPosts ? (
          <p>Loading posts...</p>
        ) : (
          posts.map((post) => (
            <div
              key={post.id}
              className="bg-white rounded-xl p-4 shadow-xl hover:shadow-2xl transition-all transform hover:-translate-y-2"
            >
              <div className="w-16 h-16 bg-gradient-to-r from-purple-600 to-pink-400 rounded-xl flex items-center justify-center mb-4 mx-auto">
                <FileText className="text-white" size={24} />
              </div>
              <h3 className="text-xl font-bold">{post.title}</h3>
              <p className="text-gray-600 mt-2">{post.body}</p>
            </div>
          ))
        )}
      </div>

      {/* Users Section */}
      <h2 className="text-2xl font-bold mt-12 mb-4">Users</h2>
      <div className="grid md:grid-cols-3 gap-6">
        {loadingUsers ? (
          <p>Loading users...</p>
        ) : (
          users.map((user) => (
            <div
              key={user.id}
              className="bg-white rounded-xl p-4 shadow-xl hover:shadow-2xl transition-all transform hover:-translate-y-2"
            >
              <div className="w-16 h-16 bg-gradient-to-r from-purple-600 to-pink-400 rounded-xl flex items-center justify-center mb-4 mx-auto">
                <UsersIcon className="text-white" size={24} />
              </div>
              <h3 className="text-xl font-bold">{user.name}</h3>
              <p className="text-gray-600">@{user.username}</p>
              <p className="text-gray-600">{user.email}</p>
            </div>
          ))
        )}
      </div>
    </div>
  );
};

export default Home;

