import React, { useState } from 'react';

import Quill from 'quill';
import 'quill/dist/quill.snow.css';
import { useCreateBlog } from '../../rest/hooks/blog';
import Button from '../components/button';
import client from '../../rest/client';
import { toast } from 'react-toastify';

const CreateBlog = () => {

    const [title, setTitle] = useState("");
    const [content, setContent] = useState("");
    const [image, setImage] = useState(null);

    const handleTitleChange = (event) => {
        setTitle(event.target.value);
    };

    const handleContentChange = (content) => {
        setContent(content);
    };

    const handleImageChange = (event) => {
        setImage(event.target.files[0]);
    };
    const { isLoading, mutate: submit, error } = useCreateBlog()

    const handleSubmit = async (event) => {
        event.preventDefault();
        let imageUrl = null;
        try {
            const formData = new FormData();
            formData.append('file', image);
            imageUrl = await client.blog.uploadFile(formData)

            submit({ content: content, image: imageUrl, title })


        } catch (error) {
            console.log(error)
            toast.error(JSON.stringify(error))
        }

    };

    const quillRef = React.useRef();

    React.useEffect(() => {
        if (quillRef.current) {
            const quill = new Quill(quillRef.current, {
                theme: 'snow',

                modules: {
                    toolbar: [
                        [{ header: [1, 2, 3, false] }],
                        ['bold', 'italic', 'underline', 'strike'],
                        [{ list: 'ordered' }, { list: 'bullet' }],
                        ['link'],
                        ['clean'],
                    ],

                },
            });

            quill.on('text-change', () => {
                handleContentChange(quill.root.innerHTML);
            });

        }
        return () => {
            quillRef.current = null;
        }
    }, []);

    return (
        <form onSubmit={handleSubmit}>
            <div className='form-group'>
                <label htmlFor="title">Title</label>
                <input
                    type="text"
                    id="title"
                    name="title"
                    value={title}
                    className="form-control"
                    onChange={handleTitleChange}
                />
            </div>
            <div className='form-group my-3'>
                <label htmlFor="image">Image</label>
                <input type="file" className="form-control" id="image" name="image" onChange={handleImageChange} />
            </div>
            <div className='mb-3'>
                <label htmlFor="content">Content</label>
                <div ref={quillRef} style={{ minHeight: "200px" }} />
            </div>
            <Button
                label="Create Blog"
                buttonType="primary"
                type="submit"
                loading={isLoading}
            />
        </form>
    );
};

export default CreateBlog;
