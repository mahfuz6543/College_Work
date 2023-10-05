import React from "react";
import { Link } from "react-router-dom";
import { logout } from "../../../utils";
import { APP_ROUTES } from "../../../utils/constants";

function Navbar({ isLoggedIn, setUser }) {


    return (
        <nav className="navbar navbar-expand-sm navbar-dark bg-dark">

            <Link className="navbar-brand" to="/">
                My Blog
            </Link>


            <ul className="navbar-nav ms-auto">
                <li className="nav-item">
                    <Link className="nav-link" to="/">
                        Home
                    </Link>
                </li>

                {isLoggedIn && (
                    <li className="nav-item">
                        <Link className="nav-link" to={APP_ROUTES.create}>
                            Create Blog
                        </Link>
                    </li>
                )}

                {!isLoggedIn ? (
                    <>
                        <li className="nav-item">
                            <Link className="nav-link" to={APP_ROUTES.login}>
                                Login
                            </Link>
                        </li>
                        <li className="nav-item">
                            <Link className="nav-link" to={APP_ROUTES.register}>
                                Register
                            </Link>
                        </li>
                    </>
                ) : (
                    <li className="nav-item">
                        <button className="nav-link btn btn-link" onClick={() => {
                            setUser(null)
                            logout()
                        }}>
                            Logout
                        </button>
                    </li>
                )}
            </ul>
        </nav>
    );
}

export default Navbar;
