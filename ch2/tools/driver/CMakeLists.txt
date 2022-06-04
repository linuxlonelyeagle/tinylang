# 设置为需要链接的llvm组件
set(LLVM_LINK_COMPONENTS
  Support 
)
# 定义可以安装应用程序
add_tinylang_tool(tinylang 
  Driver.cpp 
)

target_link_libraries(tinylang 
  PRIVATE 
  tinylangBasic
)


