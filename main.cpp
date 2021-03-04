#include <iostream>
#include <map>
using namespace std;

static map <string, pair <string, string>> * descendantName;
static string founder;

double getBlood(string candidate) {
    if (candidate == founder)
        return 1;
    else if (descendantName->count(candidate) != 0)
        return (getBlood(descendantName->at(candidate).first) + getBlood(descendantName->at(candidate).second)) / 2;
    else
        return 0;
}

int main() {
    int descendantCount = 0;
    int claimantCount = 0;
    cin >> descendantCount >> claimantCount;
    
    descendantName = new map <string, pair <string, string>>;
    cin >> founder;
    
    string claimantList[claimantCount];
    
    for (int i = 0; i < descendantCount; i++) {
        string descendant, parentA, parentB = "";
        cin >> descendant >> parentA >> parentB;
        descendantName->insert(pair<string, pair <string, string>> (descendant, {parentA, parentB}));
    }
    
    for (int i = 0; i < claimantCount; i++)
        cin >> claimantList[i];

    int bestClaimantIndex = 0;
    double bestBloodValue = 0;
    for (int i = 0; i < claimantCount; i++) {
        double bloodValue = getBlood(claimantList[i]);
        if (bloodValue > bestBloodValue) {
            bestClaimantIndex = i;
            bestBloodValue = bloodValue;
        }
    }
    cout << claimantList[bestClaimantIndex];
    return 0;
}


