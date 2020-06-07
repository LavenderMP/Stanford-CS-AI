from submission import recursive, build_dict

astr = 'the cat and the the mouse'
adict = build_dict(astr)
print(recursive(adict, 'the', 6))