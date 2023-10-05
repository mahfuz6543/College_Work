import "./blog.css";
import { Link } from "react-router-dom";
import { APP_ROUTES, IMAGE_URL } from "../../utils/constants";
import { useDeleteBlog, useBlogs } from "../../rest/hooks/blog";
import { toast } from "react-toastify";
import Button from "../components/button";

const BlogCard = ({ id, image, title, content }) => {
    const { mutate: deleteBlog, isLoading } = useDeleteBlog();
    return (
        <div className="card">
            <Link to={{ pathname: APP_ROUTES.view + id }}>
                <div
                    style={{
                        minHeight: "150px",
                        backgroundImage: `url(${IMAGE_URL + image})`,
                        backgroundSize: "cover",
                        maxHeight: "300px",
                        overflow: "hidden",
                    }}
                ></div>
            </Link>
            <div className="card-body">
                <span className="Blog-category">{title}</span>
                <p className="text-muted"></p>
                <div>
                    <Link
                        to={{
                            pathname: APP_ROUTES.update,
                            state: { data: { id, image, title, content } }
                        }}
                        state={{ data: { id, image, title, content } }}
                        className="btn btn-primary fs-6 py-1 px-4"
                    >
                        Edit
                    </Link>
                    <Button
                        loading={isLoading}
                        label="Delete Blog"
                        buttonType="danger"
                        disabled={isLoading}
                        onClick={() => deleteBlog(id)}
                        className="fs-6 py-1 px-4 ms-5"
                    />
                </div>
            </div>
        </div>
    );
};

export default function Blog() {
    const { data, isLoading, error } = useBlogs();
    if (error) {
        toast.error(error);
    }

    return (
        <div className="container">
            <h3 className="text-muted">Blog</h3>
            <div className="row">
                {isLoading &&
                    <div>Loading</div>
                }
                {data?.map((item, key) => (
                    <div key={key} className="col-12 col-md-6 col-lg-4 mb-3 px-2">
                        <BlogCard {...item} />
                    </div>
                ))}
            </div>
        </div>
    );
}