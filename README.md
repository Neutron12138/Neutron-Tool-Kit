# Neutron-Tool-Kit

简单的图形工具包

名字随便取的

项目旧地址：https://github.com/Diamond12138/Neutron-Tool-Kit

增加了ModelObject和ModelInstance

所有的ModelInstance共享同一个VAO，此VAO由ModelObject管理

使用ModelObject::create_instance()可以制造拥有相同顶点的对象，但可以为其设置不同变换

之后版本将弃用Model和PrimitiveSprite，用VertexModel与ModelInstance替代，且会在1.5.0移除（预定）
