import q2_fx as stack

# 2 implementing stack 15 points #

PRINT_FORMAT = '\nresults\t\tcontrol\n-----------------------\n'


def is_empty_test(st=stack.Stack()):
    st.push(1)  # adds and removes an elem to show that is_empty can identify when there's stuff in the stack
    t1 = st.is_empty()
    st.pop()
    t2 = st.is_empty()
    print(f"is_empty test:{PRINT_FORMAT}{t1}\t\tFalse\n{t2}\t\tTrue\n\n")


def push_test(st=stack.Stack()):
    t1 = st.to_string()  # shows the empty stack and then shows it once an element has been pushed to it
    st.push("hello")
    t2 = st.to_string()
    print(f"push test:{PRINT_FORMAT}{t1}\t\t[]\n{t2}\t['hello']\n\n")


def pop_test(st=stack.Stack()):
    st.push('world')  # prints the stack with an elem in it and then pops the elem and shows the resulting stack
    t1 = st.to_string()
    t3 = st.pop()
    t2 = st.to_string()
    print(f"pop test:{PRINT_FORMAT}{t1}\t['world']\n{t2}\t\t[]\n{t3}\t\tworld\n\n")


def top_test(st=stack.Stack()):
    st.push(1)  # adds 2 elems to stack and prints it before then getting the top of the stack and printing it as well
    st.push('two')
    t1 = st.to_string()
    t2 = st.top()
    print(f"top test:{PRINT_FORMAT}{t1}\t[1,'two']\n{t2}\t\ttwo\n\n")


def size_test(st=stack.Stack()):
    st.push(2)  # adds 4 elems to stack and then prints its size obtained from .size
    st.push(4)
    st.push(6)
    st.push(8)
    t1 = st.size()
    print(f"size test:{PRINT_FORMAT}{t1}\t\t4")


if __name__ == '__main__':
    is_empty_test()
    push_test()
    pop_test()
    top_test()
    size_test()
