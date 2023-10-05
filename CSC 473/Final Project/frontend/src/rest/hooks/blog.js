import { useMutation, useQuery, useQueryClient } from "react-query";
import { toast } from "react-toastify";
import client from "../client";

import { API_ENDPOINTS } from "../client/api-endpoints";


export const useBlogs = () => {
    return useQuery(
        [API_ENDPOINTS.blog],
        client.blog.all
    );
};

export const useBlogDetail = (id) => {
    return useQuery(
        [API_ENDPOINTS.blog, id],
        () => client.blog.one(id)
    );
};
export const useCreateBlog = () => {
    const query = useQueryClient();
    return useMutation(
        client.blog.create,
        {
            onMutate: (_) => {
                toast.success("Creating new blog, please wait...", { autoClose: true });
            },
            onSuccess: (data) => {
                toast.success("Blog created successfuly!",
                );
            },
            onSettled: () => {
                query.invalidateQueries([API_ENDPOINTS.blog]);
            },
            onError: (error, _) => {
                toast.error(error.response?.data?.message ?? error.message);
            },
        }
    );
};

export const useBlogUpdate = () => {
    const query = useQueryClient();
    return useMutation(
        client.blog.update,
        {
            onMutate: (_) => {
                toast.success("Updating new blog, please wait...", { autoClose: true });
            },
            onSuccess: (data) => {
                toast.success("Blog updated successfuly!",
                );
            },
            onSettled: () => {
                query.invalidateQueries([API_ENDPOINTS.blog]);
            },
            onError: (error, _) => {
                toast.error(error.response?.data?.message ?? error.message);
            },
        }
    );
};

export const useDeleteBlog = () => {
    const query = useQueryClient();
    return useMutation(client.blog.delete, {
        onSuccess: (data, _variable, _context) => {

            toast.success("Blog deleted successfuly!");
        },
        onSettled: () => {
            query.invalidateQueries([API_ENDPOINTS.blog]);
        },
        onError: (error, _, _previousData) => {
            toast.error(error.response?.data?.message ?? error.message);
        },
    });
};


