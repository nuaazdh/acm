//
// Created by luerfeng on 2016/01/18.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

std::vector<std::vector<std::string> > docs;
std::map<std::string, int> word_id_map;
std::vector<std::string> word_dict;
std::vector<std::set<int> > inverse_index_did;
std::vector<std::set<int> > inverse_index_word[10000];

std::string trim_word(std::string &word) {
    size_t len = word.length(), pos1 = 0, pos2 = word.length();
    while (pos1 < len && !isalnum(word[pos1])) pos1++;
    while (pos2 > 0 && !isalnum(word[pos2 - 1])) pos2--;
    if (pos2 - pos1 > 0)
        return word.substr(pos1, pos2 - pos1);
    return "";
}

int getWordId(std::string &word) {
    if (!word_id_map.count(word)) {
        word_id_map[word] = word_dict.size();
        word_dict.push_back(word);
    }
    return word_id_map[word];
}

void print_doc(const std::vector<std::string> &doc) {
    for (int j = 0; j < doc.size(); ++j) {
        std::cout << doc[j] << std::endl;
    }
}

void construct_invert_index() {
    std::string word;
    for (int i = 0; i < docs.size(); ++i) {
        for (int j = 0; j < docs[i].size(); ++j) {
            std::stringstream ss(docs[i][j]);
            while (ss >> word) {
                word = trim_word(word);
                if (word.empty())
                    continue;
                word[0] = tolower(word[0]);
                int id = getWordId(word);
                if (inverse_index_did.size() <= id) {
                    std::set<int> v;
                    inverse_index_did.push_back(v);
                }
                inverse_index_did[id].insert(i);
                if (inverse_index_word[i].size() <= j) {
                    std::set<int> vi;
                    inverse_index_word[i].push_back(vi);
                }
                inverse_index_word[i][j].insert(id);
            }
        }
    }
}

void print_docs(int docid, int wordid1, int wordid2) {
    for (int i = 0; i < inverse_index_word[docid].size(); ++i) {
        if (inverse_index_word[docid][i].count(wordid1) || inverse_index_word[docid][i].count(wordid2))
            std::cout << docs[docid][i] << std::endl;
    }
}

void find_single_word(std::string &word) {
    int wordid = word_id_map[word];
    int total = inverse_index_did[wordid].size();
    int line = 1;
    for (std::set<int>::iterator it = inverse_index_did[wordid].begin(); it != inverse_index_did[wordid].end(); ++it) {
        for (int j = 0; j < inverse_index_word[*it].size(); ++j) {
            if (inverse_index_word[*it][j].count(wordid))
                std::cout << docs[*it][j] << std::endl;
        }
        if (line != total)
            std::cout << "----------\n";
        ++line;
    }
}

int main() {
    int doc_cnt;
    std::cin >> doc_cnt;
    std::string line;
    std::string not_found("Sorry, I found nothing.\n");
    std::string docs_sperator("----------\n");
    std::string result_sperator("==========\n");
    while (doc_cnt--) {
        std::vector<std::string> doc;
        std::getline(std::cin, line);
        do {
            if (!line.empty()) doc.push_back(line);
        } while (std::getline(std::cin, line) && (line[0] != '*'));
        docs.push_back(doc);
    }
    construct_invert_index();
    int query_cnt;
    std::cin >> query_cnt;
    while (1) {
        std::getline(std::cin, line);
        if (line.empty())
            continue;
        if (query_cnt == 0)
            break;
        query_cnt--;
        std::string word1, conj, word2;
        if (line.find("AND") != std::string::npos || line.find("and") != std::string::npos) {
            std::stringstream ss(line);
            ss >> word1 >> conj >> word2;
//            std::cout<<word_invert_index[word1].size()<<"\t"<<word_invert_index[word2].size()<<std::endl;
            if (!word_id_map.count(word1) || !word_id_map.count(word2)) {
                std::cout << not_found << result_sperator;
                continue;
            }
            if (word_id_map.count(word1) && word_id_map.count(word2)) {
                std::set<int> result;
                int wordid1 = word_id_map[word1], wordid2 = word_id_map[word2];
                std::set_intersection(inverse_index_did[wordid1].begin(), inverse_index_did[wordid1].end(),
                                      inverse_index_did[wordid2].begin(), inverse_index_did[wordid2].end(),
                                      std::inserter(result, result.begin()));

//                if (result.empty()) {
//                    std::cout << not_found << result_sperator;
//                    continue;
//                }
                int total = result.size();
                int ith = 1;
                for (std::set<int>::iterator it = result.begin(); it != result.end(); ++it) {
                    print_docs(*it, wordid1, wordid2);
                    if (ith != total)
                        std::cout << docs_sperator;
                    ith++;
                }
            } else {
                if (!word_id_map.count(word1))
                    swap(word1, word2);
                find_single_word(word1);
            }
        } else if (line.find("OR") != std::string::npos || line.find("or") != std::string::npos) {
            std::stringstream ss(line);
            ss >> word1 >> conj >> word2;
//            std::cout<<word_invert_index[word1].size()<<"\t"<<word_invert_index[word2].size()<<std::endl;
            if (!word_id_map.count(word1) && !word_id_map.count(word2)) {
                std::cout << not_found << result_sperator;
                continue;
            }
            std::set<int> result;
            int wordid1 = word_id_map[word1], wordid2 = word_id_map[word2];
            std::set_union(inverse_index_did[wordid1].begin(), inverse_index_did[wordid1].end(),
                           inverse_index_did[wordid2].begin(), inverse_index_did[wordid2].end(),
                           std::inserter(result, result.begin()));
//            if (result.empty()) {
//                std::cout << not_found << result_sperator;
//                continue;
//            }
            int total = result.size();
            int ith = 1;
            for (std::set<int>::iterator it = result.begin(); it != result.end(); ++it) {
                print_docs(*it, wordid1, wordid2);
                if (ith != total)
                    std::cout << docs_sperator;
                ith++;
            }
        } else if (line.find("NOT") != std::string::npos || line.find("not") != std::string::npos) {
            std::stringstream ss(line);
            ss >> conj >> word1;
            std::set<int> result;
            if (!word_id_map.count(word1)) {
                for (int i = 0; i < docs.size(); ++i) {
                    result.insert(i);
                }
            } else {
                int wordid = word_id_map[word1];
                for (int i = 0; i < docs.size(); ++i) {
                    if (!inverse_index_did[wordid].count(i))
                        result.insert(i);
                }
            }

            if (result.empty()) {
                std::cout << not_found << result_sperator;
                continue;
            }

            int ith = 1, total = result.size();
            for (std::set<int>::iterator it = result.begin(); it != result.end(); ++it) {
                print_doc(docs[*it]);
                if (ith != total)
                    std::cout << docs_sperator;
                ith++;
            }
        } else {
            std::stringstream ss(line);
            ss >> word1;
            if (!word_id_map.count(word1)) {
                std::cout << not_found << result_sperator;
                continue;
            }
            find_single_word(word1);
        }
        std::cout << result_sperator;
    }
}

