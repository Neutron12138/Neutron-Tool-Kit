set filename=c++20
g++ -finput-charset=UTF-8 -fexec-charset=gbk -fmodules-ts -std=c++20 ^
    my_module.gcm "%filename%.cpp" -o "%filename%.exe" ^
    -lgdi32 -lopengl32 -lglew32 -lsfml-system -lsfml-window -lsfml-graphics -lfreetype -lz -lBulletDynamics -lBulletCollision -lLinearMath -lBulletSoftBody -lopenal32
"%filename%.exe"