import { useMutation, useQuery } from "react-query";
import client from "../client";
import { USER_KEY, AUTH_TOKEN_KEY } from "../../utils/constants"
import { setLocalStorageItem } from "../../utils";
import { API_ENDPOINTS } from "../client/api-endpoints";
import { toast } from "react-toastify";

export const useLogin = () => {
    return useMutation(client.users.login, {
        onMutate: () => {
            toast.success("Loging in please wait ....", { autoClose: true, closeOnClick: true });
        },
        onSuccess: (data) => {
            setLocalStorageItem(AUTH_TOKEN_KEY, data.token);
            setLocalStorageItem(USER_KEY, data.user);
        },
        onError: (error) => {
            const message = error.response?.data?.message ?? error.message;
            toast.error(message);
        },
    });
};

export const useRegister = () => {
    return useMutation(client.users.register, {
        onMutate: () => {
            toast.success("Registering please wait ....", { autoClose: true });
        },
        onSuccess: (data) => {
            setLocalStorageItem(AUTH_TOKEN_KEY, data.token);
            setLocalStorageItem(USER_KEY, data.user);
        },
        onError: (error) => {
            const message = error.response?.data?.message ?? error.message;
            toast.error(message);
        },
    });
};

export const useUser = () => {
    return useQuery(
        [API_ENDPOINTS.users],
        client.users.profileMe
    );
};