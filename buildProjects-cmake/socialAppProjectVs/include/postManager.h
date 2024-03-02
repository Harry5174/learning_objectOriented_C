#ifndef POSTMANGER_H
#define POSTMANGER_H

#include "post.h"
#include "user.h"

#include <stdexcept>
#include <vector>

class PostManager {
    private:
        std::vector<Post> posts;

    public:
        PostManager ();

        void loadPosts();
        void savePosts();
        void createPostsFile();

        void viewPosts() const;
        void postMessage(const Post& newPost);
        void clearPosts();

};

#endif