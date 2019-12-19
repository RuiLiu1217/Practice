import glob, os
os.chdir('.')
cmakefile = open("CMakeLists.txt", "w")
cmakefile.write("PROJECT(Practice)\n")
cmakefile.write("ADD_LIBRARY(Practice STATIC\n")
for file in glob.glob("*.hpp"):
    cmakefile.write("\t")
    cmakefile.write(file)
    cmakefile.write("\n")

for file in glob.glob("*.cpp"):
    cmakefile.write("\t")
    cmakefile.write(file)
    cmakefile.write("\n")
cmakefile.write(")")
cmakefile.close()