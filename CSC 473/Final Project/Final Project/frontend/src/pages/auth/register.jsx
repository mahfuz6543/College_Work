import React from "react";
import "./auth.css";
import { useNavigate } from "react-router-dom";
import { useRegister } from "../../rest/hooks/user";
import { APP_ROUTES } from "../../utils/constants"
import Button from "../components/button";


function Register({setUser}) {
    const [state, setState] = React.useState({
        username: "",
        password: "",
    });
    const handleChange = (e) => {
        setState({ ...state, [e.target.name]: e.target.value });
    };
    const { mutate: register, isSuccess, isLoading, data } = useRegister();

    const navigate = useNavigate();
    const submitForm = async (e) => {
        e.preventDefault();
        register(state);
    };

    React.useEffect(() => {
        setUser(data?.user)
        isSuccess && navigate(APP_ROUTES.home);
    });
    return (
        <div className="container register">
            <div className="d-flex mt-5">
                <div className="col-12 col-md-8 col-lg-6  mx-auto">
                    <div className="card card1  px-4">
                        <div className="row justify-content-center my-auto">
                            <form onSubmit={submitForm}>
                                <div className="col-12 my-5 mx-auto">
                                    <h3 className="text-center heading">Register</h3>
                                    <div className="form-group my-2">
                                        <label className="form-control-label text-muted">
                                            Username
                                        </label>
                                        <input
                                            required
                                            type="username"
                                            id="username"
                                            name="username"
                                            placeholder="username"
                                            className="form-control"
                                            value={state.username}
                                            onChange={handleChange}
                                        />
                                    </div>
                                    <div className="form-group my-2">
                                        <label className="form-control-label text-muted">
                                            Password
                                        </label>
                                        <input
                                            required
                                            type="password"
                                            id="psw"
                                            name="password"
                                            placeholder="Password"
                                            className="form-control"
                                            value={state.password}
                                            onChange={handleChange}
                                        />
                                    </div>
                                    <div className="row justify-content-center my-3 px-3">
                                        <Button
                                            label="Register"
                                            buttonType="primary"
                                            type="submit"
                                            loading={isLoading}
                                        />
                                    </div>
                                    <div className="row justify-content-center my-2">
                                        {/* TODO - Implement forgot password */}
                                        <a href={APP_ROUTES.login}>
                                            <small className="text-muted">You have an account? Login</small>
                                        </a>
                                    </div>
                                </div>
                            </form>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    );
}

export default Register;