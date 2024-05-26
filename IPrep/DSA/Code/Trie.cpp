/*
IPrep/DSA/Trie.cpp
*/

#include <iostream>

using namespace std;

class TrieNode
{
    TrieNode *node[26];
    bool isEnd;

    int getPos(char c)
    {
        return c - 'a';
    }

public:
    TrieNode()
    {
        this->isEnd = false;
    }

    bool hasCharacter(char c)
    {
        return node[getPos(c)] != NULL;
    }

    TrieNode *getCharacter(char c)
    {
        return node[getPos(c)];
    }

    void markAsEnd()
    {
        this->isEnd = true;
    }

    bool insertCharacter(char c)
    {
        if (!hasCharacter(c))
        {
            node[getPos(c)] = new TrieNode();
            return true;
        }
        return false;
    }

    bool isEndOfWord()
    {
        return this->isEnd;
    }
};

class Trie
{
    TrieNode *node;

public:
    Trie()
    {
        this->node = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *temp = node;
        for (char c : word)
        {
            temp->insertCharacter(c);
            temp = temp->getCharacter(c);
        }

        temp->markAsEnd();
    }

    bool isWordPresent(string word)
    {
        TrieNode *temp = node;
        for (char c : word)
        {
            if (!temp->hasCharacter(c))
            {
                return false;
            }
            temp = temp->getCharacter(c);
        }
        return temp->isEndOfWord();
    }

    bool isPrefixPresent(string word)
    {
        TrieNode *temp = node;
        for (char c : word)
        {
            if (!temp->hasCharacter(c))
            {
                return false;
            }
            temp = temp->getCharacter(c);
        }
        return temp != NULL;
    }
};

int main()
{
    Trie *root = new Trie();
    cout << root->isPrefixPresent("hell") << "\n";
    root->insert("hello");
    cout << root->isWordPresent("hello") << "\n";
    cout << root->isPrefixPresent("hell") << "\n";

    cout << root->isWordPresent("world") << "\n";
    root->insert("world");
    cout << root->isWordPresent("world") << "\n";

    return 0;
}