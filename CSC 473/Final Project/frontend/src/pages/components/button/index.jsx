import classNames from "classnames";
import React from "react";
import ProgressBar from "./loader";


const btnSize = {
    small: "btn-sm",
    medium: "",
    large: "btn-lg",
};
const btnType = {
    primary: "btn-primary",
    secondary: "btn-secondary",
    success: "btn-success",
    danger: "btn-danger",
};

const Button = ({
    size = "medium",
    buttonType,
    className,
    loading = false,
    ...props
}) => {
    const c = classNames(
        "btn",
        className,
        btnSize[size],
        btnType[buttonType],
        "fs-6",
        "py-1",
        "px-4"
    );
    return (
        <button {...props} className={c} type={props.type}>
            {!loading && props.label}
            {loading && <ProgressBar />}
        </button>
    );
};

export default Button;