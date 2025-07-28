class Node {
    public:
    Node* list[26];
    bool is_word;
    
    Node()
    {
        for (int i = 0; i < 26; ++i)
        {
            list[i] = nullptr;
        }

        is_word = false;
    }
};

class Trie {
public:
    Node* root;
    Trie()
    {
        root = new Node;
    }
    
    void insert(string word)
    {
        Node* curr = root, *next;
        int len = word.size();

        for (int i = 0; i < len; ++i)
        {
            cout << word[i];
            next = curr->list[word[i] - 'a'];
            if (next)
            {
                curr = next;
            }
            else
            {
                curr->list[word[i] - 'a'] = new Node;
                curr = curr->list[word[i] - 'a'];
            }
        }
        curr->is_word = true;   
    }
    
    bool search(string word)
    {
        Node* curr = root, *next;
        int len = word.size();

        for (int i = 0; i < len; ++i)
        {
            next = curr->list[word[i] - 'a'];
            if (next)
            {
                curr = next;
            }
            else
            {
                return false;
            }
        }

        return curr->is_word;        
    }
    
    bool startsWith(string prefix)
    {
        Node* curr = root, *next;
        int len = prefix.size();

        for (int i = 0; i < len; ++i)
        {
            next = curr->list[prefix[i] - 'a'];
            if (next)
            {
                curr = next;
            }
            else
            {
                return false;
            }
        }

        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */