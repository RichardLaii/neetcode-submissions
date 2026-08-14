/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    int i = 0;
    vector<string> tokens;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "null,";
        return to_string(root->val) + ","
                + serialize(root->left)
                + serialize(root->right);

    }

    TreeNode* build(){
        string val = tokens[i++];
        
        if (val == "null")
            return nullptr;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = build();
        node->right = build();

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;

        tokens.clear();
        i = 0;
        while (getline(ss, token, ','))
            tokens.push_back(token);
        return build();
    }
};
