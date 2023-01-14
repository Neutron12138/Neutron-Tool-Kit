set filename=main
g++ -finput-charset=UTF-8 -fexec-charset=gbk ^
    "%filename%.cpp" -o "%filename%.exe" ^
    -lgdi32 -lopengl32 -lglew32 -lsfml-system -lsfml-window -lsfml-graphics -lfreetype -lz
"%filename%.exe"