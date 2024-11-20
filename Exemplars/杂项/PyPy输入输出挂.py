import sys
import io

# 检查是否为 PyPy
if sys.implementation.name == "pypy":
    import atexit

    # 根据 Python 版本区分处理方式
    if sys.version_info[0] == 2:  # PyPy2
        original_stdout = sys.stdout
        original_stdin = sys.stdin

        # 替换 stdout
        sys.stdout = io.BytesIO()

        # 在程序退出时写回原始 stdout
        def flush_stdout():
            original_stdout.write(sys.stdout.getvalue())
            original_stdout.flush()

        atexit.register(flush_stdout)

        # 替换 stdin
        sys.stdin = io.BytesIO(sys.stdin.read())
        input = lambda: sys.stdin.readline().rstrip()  # 定义兼容的 input() 函数

    elif sys.version_info[0] == 3:  # PyPy3
        original_stdout = sys.stdout
        original_stdin = sys.stdin

        # 替换 stdout
        sys.stdout = io.StringIO()

        # 在程序退出时写回原始 stdout
        def flush_stdout():
            original_stdout.write(sys.stdout.getvalue())
            original_stdout.flush()

        atexit.register(flush_stdout)

        # 替换 stdin
        sys.stdin = io.StringIO(sys.stdin.read())  # 确保使用文本流
        input = lambda: sys.stdin.readline().rstrip()  # 定义兼容的 input() 函数
