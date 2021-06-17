# -*- coding: utf-8 -*-
# 信号を可視化して画像にしてくれるpythonスクリプト。
# この中身は理解しないでいいです。

import argparse
import matplotlib.pylab as plt

parser = argparse.ArgumentParser()
parser.add_argument("--signal", default="signal.txt")
parser.add_argument("--img", default="out.png")
args = parser.parse_args()

if __name__ == "__main__":
    with open(args.signal, "rt") as f:
        ys = [float(v.rstrip()) for v in f]
    ts = list(range(len(ys)))

    plt.plot(ts, ys, '.--', linewidth=1)
    plt.xlabel('t')
    plt.ylabel('f(t)')
    plt.savefig(args.img)

