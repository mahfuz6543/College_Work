import HttpClient from "./http-client";
import { API_ENDPOINTS } from "./api-endpoints"

const FORM_HEADERS = { "Content-Type": "multipart/form-data" };


class Client {
    users = {
        login: ({ username, password }) =>
            HttpClient.post(API_ENDPOINTS.login, { username, password }),
        register: ({ username, password }) =>
            HttpClient.post(API_ENDPOINTS.register, { username, password }),

        profile: (id) => HttpClient.get(API_ENDPOINTS.users + "/" + id),
        profileMe: () => HttpClient.get(API_ENDPOINTS.users)
    };

    blog = {
        all: () => HttpClient.get(API_ENDPOINTS.blog),
        one: (id) => HttpClient.get(API_ENDPOINTS.blog + "/" + id),
        uploadFile: (form) => {
            return HttpClient.post(API_ENDPOINTS.uploads, form, { headers: FORM_HEADERS })
        },
        create: ({ content, title, image }) => HttpClient.post(API_ENDPOINTS.blog, { content, title, image }),
        delete: (id) => HttpClient.delete(API_ENDPOINTS.blog + "/" + id),
        update: ({ content, title, image, id }) => HttpClient.post(API_ENDPOINTS.blog + "/" + id, { content, title, image }),
    }
}

export default new Client()