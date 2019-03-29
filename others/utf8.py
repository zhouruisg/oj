import glob, codecs

for fn in glob.glob("../*.*",recursive=True):
    print(fn)
    data = open(fn, "rb").read()
    if data.startswith(codecs.BOM_UTF8):
        # Already UTF-8
        continue
    # else assume ANSI code page
    data = data.decode("mbcs")
    data = codecs.BOM_UTF8 + data.encode("utf-8")
    open(fn, "wb").write(data)