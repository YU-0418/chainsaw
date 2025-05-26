# chainsaw库

## 风格
收集常用的日常处理代码的方法

所有的代码页宏采用```CHAINSAW_[dir_name]_[file_name][_][suffix]```

跟1.0.0的区别就是封装成动态库

所有的代码注释使用简洁易懂的英文来表达

头文件记录函数声明，impl文件夹下记录函数实现

## 目录

### head
记录常用的头文件
- head_common.h

### common
chainsaw库中最常用的一些方法
- chartool.h
字符处理
- print.h
打印信息
- read_config_message.h
读取设置文件信息，以'#[space]'开头的通常为key，而以下接的是值
- readwritefile.h
读写文件，判断文件是否存在
- option.h
用于便捷的方法拓展使用，格式为"-[alpha]"
- command.h
用于属于命令

#### stringtool
字符串处理，灵感来源于bash
- stringtool.h
常规处理字符
- cut.h
按照固定字符将字符串分开

### error_message
打印错误信息
- print_err.h

### argv
处理命令行参数
-argv_tool.h

### c_code
部分纯c代码，多用于复制修改，暂且不用

### html
用固定形式来生成html格式的控件样式
-table.h

### markdown
用固定形式来生成markdown格式的固定样式
-table.h
