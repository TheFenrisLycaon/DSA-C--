def make_readable(seconds):
    mi, seconds = seconds//60, seconds%60
    hours, mi = mi//60, mi%60
    
    return str("{:02d}".format(hours)) + ":" + str("{:02d}".format(mi)) + ':' + str("{:02d}".format(seconds))