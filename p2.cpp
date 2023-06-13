

//Determine algorithm complexity( big o notation)
void example_function(std::vector<int>& ns) {
    std::sort(begin(ns), end(ns)); 
    
    int n = size(ns);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n * n; j *= 2){
            auto it = std::lower_bound(begin(ns), end(ns), j);
            if (it != end(ns) && *it == j){
                std::cout << "Found " << j << std::endl;
            }
        }
    }
}