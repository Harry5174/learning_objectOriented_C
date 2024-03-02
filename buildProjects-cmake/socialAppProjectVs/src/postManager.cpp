#include "postManager.h"

#include <fstream>
#include <iostream>

// CONSTRUCTOR
PostManager::PostManager() {
    try {
  // Check and create the file if it doesn't exist
        loadPosts();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
};

// FILE-HANDLING
void PostManager::createPostsFile() {
    std::ofstream postsFile("posts.txt");
    if (postsFile.is_open()) {
        postsFile.close();
    } else {
        std::cerr << "Error creating posts file." << std::endl;
    }
}

void PostManager::loadPosts() {
    createPostsFile();
    std::ifstream postsFile("posts.txt");
    if (postsFile.is_open()) {
        std::string line;
        while (getline(postsFile >> std::ws, line)) {
            size_t pos = line.find(",");
            if (pos != std::string::npos) {
                std::string userName = line.substr(0, pos);
                std::string content = line.substr(pos + 1);

                posts.push_back(Post(userName, content));  // anonymous object
            }
        }
        postsFile.close();
    }
}

/// writing to a file
void PostManager::savePosts() {
    std::ofstream postFile("posts.txt");
    if (postFile.is_open()) {
        for (const auto &post : posts) {
            postFile << post.getUserName() << "," << post.getContent() << "\n";
        }
        postFile.close();
    }
}

// OTHER METHODS
void PostManager::viewPosts() const {
    if (posts.empty()) {
        std::cout << "No post available" << std::endl;
    } else {
        std::cout << "\n======= Posts =======\n";
        for (const auto &post : posts) {
            post.displayDetails();
        }
    }
}

void PostManager::postMessage(const Post &newPost) {
    posts.push_back(newPost);
    std::cout << "Message Posted successfully!" << std::endl;
}

void PostManager::clearPosts() {
    posts.clear();
}
