g++ -finput-charset=UTF-8 -fexec-charset=gbk -DBUILDING_DLL=1 -shared ^
    "../src/DLL.cpp" -o "NTK.dll" ^
    -lgdi32 -lopengl32 -lglew32 -lsfml-system -lsfml-window -lsfml-graphics -lfreetype -lz -lBulletDynamics -lBulletCollision -lLinearMath -lBulletSoftBody -lopenal32