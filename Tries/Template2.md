# Not heavily Tested!!

    struct Node{
        bool isEnd = false;
        Node * PointerToChildren[26];
        int count = 0;
    
        bool isEndOfString(){
            return isEnd;
        }
    
        void setStringEnd(){
            isEnd = true;
        }
    
        Node *goToChildNode(char ch){
            return PointerToChildren[ch - 'a'];
        }
    
        void AddChild(char ch){
            PointerToChildren[ch - 'a'] = new Node();
        }
    
        bool hasChildAlready(char ch){
            return (PointerToChildren[ch - 'a'] != NULL);
        }
    
        bool isLastNode(){
            for(int i = 0; i < 26; i++){
                if(PointerToChildren[i] != NULL) return false;
            }
            return true;
        }
    
        void setCount(int ct){
            count = ct;
        }
    
        int getCount(){
            return count;
        }
    
    };
    
    struct Trie{
        Node *root;
        Trie(){
            root = new Node();
        }
    
        void InsertString(string s){
            Node *currNode = root;
    
            for(int i = 0; i < size(s); i++){
                if(!currNode -> hasChildAlready(s[i])){
                    currNode -> AddChild(s[i]);
                }
                currNode = currNode -> goToChildNode(s[i]);
            }
    
            currNode -> setStringEnd();
        }
    
        bool SearchString(string s){
            Node * currNode = root;
            for(int i = 0; i < size(s); i++){
                if(!currNode -> hasChildAlready(s[i])) return false;
                currNode = currNode -> goToChildNode(s[i]);
            }
    
            return currNode -> isEndOfString();
        }
    
    
        bool hasPrefix(string s){
            Node * currNode = root;
            for(int i = 0; i < size(s); i++){
                if(!currNode -> hasChildAlready(s[i])) return false;
                currNode = currNode -> goToChildNode(s[i]);
            }
            return true;
        }
    
        int preCompute(Node *currNode){
    
            if(currNode -> isLastNode() && currNode -> isEndOfString()) return 1;
    
            int ct = 0;
    
            for(int i = 0; i < 26; i++){
                if(currNode -> hasChildAlready(char(i + 'a'))){
                   ct += preCompute(currNode -> goToChildNode(char(i + 'a')));
                }
            }
    
            if(currNode -> isEndOfString()){
                currNode -> setCount(ct + 1);
                return ct + 1;
            }
            else{
                currNode -> setCount(ct);
                return ct;
            }
        }
    
        void BuildPrecompute(){
            Node * currNode = root;
            int x = preCompute(currNode);
        }
    
        int countPrefix(string prefix){
    
            Node *currNode = root;
    
            currNode = root;
            for(int i = 0; i < size(prefix); i++){
                if(!currNode -> hasChildAlready(prefix[i])) return 0;
                currNode = currNode -> goToChildNode(prefix[i]);
            }
            return currNode -> getCount();
        }
    };
    
    void Solve(){
        vector<string>str = {"abc", "ab", "abcdef", "abef", "abcmp"};
    
        Trie trie = Trie();
    
        for(auto x : str) trie.InsertString(x);
    
        trie.BuildPrecompute();
    
        int ans = trie.countPrefix("abc");
        
        int x = trie.hasPrefix("abcm");
    
        cout << x << lb;
         
        cout << ans << lb;
    }
