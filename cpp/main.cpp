#include "../include/func.h"

int main(int argc, char** argv) {

    if (argc < 2) {
        exit(1);
    }
    
    ExecuteHelpMaybe(argv[1]);
    ExecuteViewMaybe(argv[1], argc == 3 ? argv[2] : "");
    ExecuteAddMaybe(argv[1]);
    ExecuteNamesMaybe(argv[1]);
    ExecuteSumMaybe(argv[1], argc == 3 ? argv[2] : "");
    ExecuteMaxMaybe(argv[1]);
    ExecuteDestroyMaybe(argv[1]);

    return 0;
}