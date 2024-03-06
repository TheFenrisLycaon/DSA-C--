def generate_hashtag(s):
    if len(s)>0 and len(s) < 140:
        return ('#'+ ''.join([x[0].upper()+ x[1:].lower() if len(x) > 1 else x.upper() for x in s.split(' ')]))
    else:
        return False