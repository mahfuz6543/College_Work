import axios, { AxiosRequestConfig } from "axios";
import { getAuthToken, logout } from "../../utils"
import { BASE_URL } from "../../utils/constants"

const Axios = axios.create({
    baseURL: BASE_URL,
    headers: {
        "Content-Type": "application/json",
    },
});
Axios.interceptors.request.use((config) => {
    config.headers = {
        ...config.headers,
        Authorization: getAuthToken(),
    };

    return config;
});

Axios.interceptors.response.use(
    (response) => response,
    (error) => {
        if (error.status === 401 || error.status === 403) {
            //clear user authentication whenever the auth token is invalid
            logout();
            window.location.replace("/login");
        }
        error.message =
            error.response?.msg ?? error.response?.message ?? error.message;
        return Promise.reject(error);
    }
);

class HttpClient {
    static async get(url, params) {
        const res = await Axios.get(url, { params });
        return res.data;
    }
    /**
     * 
     * @param {string} url string
     * @param {any} data 
     * @param {AxiosRequestConfig} options  
     * @returns 
     */
    static async post(
        url,
        data,
        options
    ) {
        const res = await Axios.post(url, data, options);
        return res.data;
    }
    static async delete(url) {
        const res = await Axios.delete(url);
        return res.data;
    }
    /**
     * 
     * @param {string} url 
     * @param {any} data 
     * @param {AxiosRequestConfig} options 
     * @returns 
     */
    static async put(
        url,
        data,
        options
    ) {
        const res = await Axios.put(url, data, options);
        return res.data;
    }
}

export default HttpClient;