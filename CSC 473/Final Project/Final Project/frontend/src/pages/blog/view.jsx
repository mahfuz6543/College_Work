import React, { } from "react";
import { useParams } from "react-router-dom";
import { useBlogDetail } from "../../rest/hooks/blog";
import { IMAGE_URL } from "../../utils/constants";

function BlogView() {
    const { id } = useParams();
    const { data: blogPost, isLoading } = useBlogDetail(id);

    return (
        <div>
            {isLoading && <div>Loading ....</div>}
            {blogPost ? (
                <div>
                    <h1>{blogPost.title}</h1>
                    <img src={IMAGE_URL + blogPost.image} alt={blogPost.title} className="img img-round mx-auto d-block"
                        style={{ maxHeight: "300px", width: "auto" }}
                    />
                    <div dangerouslySetInnerHTML={{ __html: blogPost.content }}></div>
                </div>
            ) : (
                <p>Loading blog post...</p>
            )}
        </div>
    );
}

export default BlogView;
