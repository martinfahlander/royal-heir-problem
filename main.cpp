#include <iostream>
#include <map>
using namespace std;

static map <string, pair <string, string>> * relations;
static string king;

double getHeritage(string descendant) {
    
    // Descendant is the king
    if (descendant == king)
        return 1;

    // Descendant has a parent which may have royal blood
    // Recursive function calculates parent heritage until it reaches either king or no royal blood
    else if (relations->count(descendant) != 0)
        return (getHeritage(relations->at(descendant).first)
                + getHeritage(relations->at(descendant).second)) / 2;
    
    // Descendant has no royal blood
    else
        return 0;
    
}

int main() {
    
    // Number of relations within the royal family and number of candidates to be considered
    int relationCount = 0; cin >> relationCount;
    int candidateCount = 0; cin >> candidateCount;
    cin >> king;
    
    // Map with all parent-child relations and array with candidates
    relations = new map <string, pair <string, string>>;
    string candidates[candidateCount];
    
    // Insert names from input into relations
    for (int i = 0; i < relationCount; i++) {
        string descendant, firstParent, secondParent = "";
        cin >> descendant >> firstParent >> secondParent;
        relations->insert(pair<string, pair <string, string>> (descendant, {firstParent, secondParent}));
    }
    
    // Insert names from input into candidates
    for (int i = 0; i < candidateCount; i++)
        cin >> candidates[i];

    // Find candidate with the most amount of royal heritage
    int bestCandidate = 0;
    double bestHeritage = 0;
    for (int i = 0; i < candidateCount; i++) {
        double heritage = getHeritage(candidates[i]);
        if (heritage > bestHeritage) {
            bestCandidate = i;
            bestHeritage = heritage;
        }
    }
    cout << candidates[bestCandidate];
    return 0;
    
}
