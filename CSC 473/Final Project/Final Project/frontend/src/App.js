import { Route, Routes } from "react-router-dom";
import { APP_ROUTES, USER_KEY } from "./utils/constants";
import Login from "./pages/auth/login";
import Register from "./pages/auth/register";
import React from "react";
import { getAuthToken, getItemFromLocalStorage } from "./utils"
import Navbar from "./pages/components/button/navbar";
import Blog from "./pages/blog/list"
import { ToastContainer } from 'react-toastify';
import 'react-toastify/dist/ReactToastify.css';

import BlogView from "./pages/blog/view";
import BlogUpdate from "./pages/blog/update";
import CreateBlog from "./pages/blog/create";




function App() {
  const [user, setUser] = React.useState(null);
  React.useEffect(() => {
    const user_ = getItemFromLocalStorage(USER_KEY);
    if (user_) {
      console.log(user_)
      setUser(user_)
    }
  })
  return (
    <>  <Navbar isLoggedIn={user} setUser={setUser} />
      <div className="container mx-auto my-3">
        <ToastContainer />
        <Routes>
          <Route path={APP_ROUTES.login} element={<Login setUser={setUser} />} />
          <Route path={APP_ROUTES.register} element={<Register setUser={setUser} />} />
          <Route path={APP_ROUTES.home} element={<Blog />} />
          <Route path={APP_ROUTES.create} element={<CreateBlog />} />
          <Route path={APP_ROUTES.update} element={<BlogUpdate />} />
          <Route path={APP_ROUTES.view + ":id"} element={<BlogView />} />
        </Routes>
      </div>

    </>
  );
}

export default App;
