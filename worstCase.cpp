#include <iostream>
#include <vector>


void worstCase(int n){
    std::cout<<n<<std::endl;
    for (int i = n; i >= 1; --i) {
    std::cout << i << " ";
    }
    std::cout<<std::endl;
}


int main(int argc, char* argv[]) {
    if(argc !=2){
        std::cerr <<"missing arr size of: "<<argv[0]<<std::endl;
        return 1;
    }
    int n= std::atoi(argv[1]);

    for(int i= 1; i<= n; i++){
            worstCase(i*10);
    }
    return 0;
}
