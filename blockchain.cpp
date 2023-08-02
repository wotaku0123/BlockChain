#include <iostream>
#include <ctime>
#include <vector>
#include <map>

using namespace std;

class BlockChain {
private:
    vector<string> transaction_pool;
    vector<map<string, string> >  chain;

public:
    // Constructor
    BlockChain() {
        transaction_pool.clear(); // 初期化
        chain.clear();
        create_block(0, "init hash");
    }

        // ブロックの生成メソッド
    void create_block(int nonce, const string& previous_hash) {
        // Get the current time
        time_t current_time = time(nullptr);

        // Create new block information
        map<string, string> block;
        block["timestamp"] = to_string(current_time);
        block["nonce"] = to_string(nonce);
        block["previous_hash"] = previous_hash;

        // Add new transactions into the block
        for (const auto& transactions : transaction_pool) {
            block["transactions"] += transactions + ":";
        }

        // Add new block into the chain
        chain.push_back(block);

        // Clear transaction_pool
        transaction_pool.clear();

        // Print new block
        cout << "New Block Created: " << endl;
        for (const auto& pair : chain.back()) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }

    // チェーンの出力メソッド
    void printChain() const {
        for (const auto& block : chain) {
            cout << "Block: { ";
            for (const auto& pair : block) {
                cout << pair.first << ": " << pair.second << ", ";
            }
            cout << "}" << std::endl;
        }
    };

    void pprint(){
        for(size_t i = 0; i < chain.size(); ++i){
            cout << string(25, '=') << "Chain" << i << " " << string(25, '=') << endl;
            for(const auto& kvp: chain[i]){
                cout << string(15, ' ') << kvp.first << ": " << kvp.second << endl;
            }
        }
        cout << string(58, '*') << endl;
    };
};

int main() {
    BlockChain block_chain;
    block_chain.pprint();

    block_chain.create_block(5, "hash 1");
    block_chain.pprint();
    block_chain.create_block(2, "hash 2");
    block_chain.pprint();


    return 0;
}
