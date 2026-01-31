#include "hw.h"
#include "wr_file.h"

int main(int arhc, char** argv){

    utils_app::info();
    WriteReadFile wr;

    wr.readFromFile();
    wr.writeToFile();

    return 0;
}