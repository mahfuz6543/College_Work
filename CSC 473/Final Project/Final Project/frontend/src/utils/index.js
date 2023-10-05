import { AUTH_TOKEN_KEY } from "./constants";

export const getItemFromLocalStorage = (key) => {
    try {
        return localStorage.getItem(key);
    } catch (e) {
        return null;
    }
};

export const setLocalStorageItem = (key, value) => {
    try {
        localStorage.setItem(key, value);
        return true;
    } catch (e) {
        return false;
    }
};


export const getAuthToken = () => {
    return getItemFromLocalStorage(AUTH_TOKEN_KEY) ?? "";
};

export const logout = () => {
    localStorage.clear();
    window.location.pathname = "/"
};