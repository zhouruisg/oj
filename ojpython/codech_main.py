import os
from glob import glob

'''
import importlib.util
spec = importlib.util.spec_from_file_location("module.name", "/path/to/file.py")
foo = importlib.util.module_from_spec(spec)
spec.loader.exec_module(foo)
foo.MyClass()
'''

def get_testcase0(fn):
    myobject = __import__(fn, globals(), locals(), [fn])
    if hasattr(myobject, 'testcase'):
        print("found test case", fn)
    else:
        pass

import importlib.util
def get_testcase(mn, fn):
    spec = importlib.util.spec_from_file_location(mn, fn)
    foo = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(foo)
    if hasattr(foo, 'testcase'):
        print("found test case", fn)
        #foo.testcase()
        return fn, foo.testcase
    else:
        return None, None


def dirfile(rootdir):
    for subdir, dirs, files in os.walk(rootdir):
        for file in files:
            #print os.path.join(subdir, file)
            filepath = subdir + os.sep + file
            if filepath.endswith(".py"):
                print (file, filepath)
                get_testcase(file, filepath)

def walk():
    rootdir = "./"
    tclist = []
    for subdir, dirs, files in os.walk(rootdir):
        for file in files:
            #print os.path.join(subdir, file)
            filepath = subdir + os.sep + file
            if filepath.endswith(".py"):
                #print (file, filepath)
                fn, tc = get_testcase(file, filepath)
                if fn and tc:
                    tclist.append((fn, tc))

    for idx, tp in enumerate(tclist):
        print('{0:4}{1:>80}'.format(idx,tp[0]))

    choose = input("select test file:")
    func = tclist[int(choose)][1]
    func()

    '''
    PATH = "./"
    result = [y for x in os.walk(PATH) for y in glob(os.path.join(x[0], '*.py'))]
    dct = dict((i,result[i]) for i in range(0, len(result)))

    for key in dct:
        get_testcase(dct[key])
        print key, ":", dct[key]
    choose = input("select test file:")
    tf = dct[int(choose)]

    os.system('python '+ tf)
    '''



if __name__ == '__main__':
    walk()
