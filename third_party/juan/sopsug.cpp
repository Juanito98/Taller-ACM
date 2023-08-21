#include <iostream>
#include <utility>
#include <unordered_set>
#include <vector>

typedef std::pair<int, int> pii;

const int MAXN = 300002;

int n, m, k;

int padre[MAXN];
std::unordered_set<int> componentIds;
std::unordered_set<int>* componentNodes[MAXN];

int raiz(int nodo) {
    if (padre[nodo] == nodo) {
        return nodo;
    }
    return padre[nodo] = raiz(padre[nodo]);
}

// a -> b
// Regresa si es posible
bool join(int a, int b) {
    // Regresa true 
    int ra = raiz(a);
    int rb = raiz(b);
    if (ra != a || ra == rb) {
        // Las aristas son dirigidas.
        // Imposible que sea un arbol valido
        return false;
    }
    // Merge ra with rb (ra -> rb)
    padre[ra] = rb;
    componentIds.erase(ra);
    // Small to large merge
    if (componentNodes[ra]->size() > componentNodes[rb] -> size()) {
        std::swap(componentNodes[ra], componentNodes[rb]);
    }
    for (auto h : *componentNodes[ra]) {
        componentNodes[rb] -> insert(h);
    }
    componentNodes[ra] -> clear();
    return true;
}

std::unordered_set<int> couldNotJoinWith[MAXN];

int canJoinTo(int nodo, const std::unordered_set<int>& nodes) {
    for (auto h : nodes) {
        if (couldNotJoinWith[nodo].count(h) == 0) {
            return h;
        }
    }
    return -1;
}

int main() {
    std::cin >> n >> m >> k;
    std::vector<pii> ans;
    bool posible = true;

    // Inicializa componentes
    for (int i = 0; i < n; ++i) {
        padre[i] = i;
        componentIds.insert(i);
        componentNodes[i] = new std::unordered_set<int>({i});
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        posible &= join(a, b);
        ans.push_back({a, b});
    }
    for (int i = 0; i < k; ++i) {
        int a, b;
        std::cin >> a >> b;
        couldNotJoinWith[a].insert(b);
    }
    int rootChosen = -1; // Id of the component chosen as root
    while (ans.size() < n - 1 && posible) {
        // Extract whatever component
        // For that component, try to find any node
        // that can be connected
        const int compId = *(componentIds.begin());
        componentIds.erase(compId);
        bool joined = false;
        // Tratemos de unirlo con otra componente
        for (auto compId2 : componentIds) {
            if (joined) break;
            int canJoinToNode = canJoinTo(compId, *componentNodes[compId2]);
            if (canJoinToNode != -1) {
                // Sí puedo unirlos
                join(compId, canJoinToNode);
                ans.push_back({compId, canJoinToNode});
                joined = true;
            }
        }
        if (!joined) {
            // Tratemos con raiz de arbol o que este sea raiz
            if (rootChosen == -1) {
                rootChosen = compId;
            } else {
                int canJoinToNode = canJoinTo(compId, *componentNodes[rootChosen]);
                if (canJoinToNode != -1) {
                    // Lo uno
                    join(compId, rootChosen);
                    ans.push_back({compId, canJoinToNode});
                    joined = true;
                } else {
                    // No puedo tener dos raices
                    posible = false;
                }
            }
        }
    }

    if (!posible) {
        std::cout << "NO\n";
    } else {
        for (auto p : ans) {
            std::cout << p.first << " " << p.second << std::endl;
        }
    }

    return 0;
}
