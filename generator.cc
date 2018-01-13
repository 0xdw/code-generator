#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

std::string toUpperCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

int main(int argc, char* argv[]) {

    std::string name = argv[1];
    std::string class_name = argv[2];

    std::ofstream source_file;
    std::ofstream header_code;

    source_file.open (name + ".cc");
    header_code.open (name + ".h");

    source_file << "#include \"" + name + ".h\"\n\n";
    source_file << "" + class_name + "::" + class_name + "() { }\n";
    source_file << "" + class_name + "::~" + class_name + "() { }\n";

    std::string header = toUpperCase(name) + "_H";

    header_code << "#ifndef " + header + "\n";
    header_code << "#define " + header + "\n\n";
    header_code << "class " + class_name + " {\n";
    header_code << "    public:\n";
    header_code << "        " + class_name + "();\n";
    header_code << "        ~" + class_name + "();\n";
    header_code << "};\n\n";
    header_code << "#endif // " + header + "\n";
    
    source_file.close();
    header_code.close();

    return 0;
}
