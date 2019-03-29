import glob, codecs

#configfiles = glob.glob(r'C:\Users\sam\Desktop\**\*.txt', recursive=True)
#fn="ojcpp/company/memo.txt"

    

for fn in glob.glob("ojcpp/company/*.cpp",recursive=True):
    print(fn)
    ret=True
    try:
        data = open(fn, "r", encoding="gbk").read()    
        open(fn, "w", encoding="utf-8").write(data)
    except:
        ret=False
    
    """
    if ret:
        continue
        
    try:
        data = open(fn, "r", encoding="utf-8").read()    
        open(fn, "w", encoding="utf-8").write(data)
    except:
        pass
    """

    