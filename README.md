# RayTracing-TheRestOfYourLife
[Ray Tracing: The Rest of Your Life](https://raytracing.github.io/books/RayTracingTheRestOfYourLife.html)([日本語版](https://inzkyk.xyz/ray_tracing_in_one_weekend/))を学んでいる記録。[レイトレ三部作のgithubリンク](https://github.com/RayTracing/raytracing.github.io)

wip:

![](image.png)

---

# メモ

## MCでπを求める
動かし続けるタイプでは3.1415まで収束。次の桁は収束する前にオーバーフロー

## MCでπ、層化サンプリング
Regular    Estimate of Pi = 3.141514800000

Stratified Estimate of Pi = 3.141589480000

## x^2, [0,2)の積分値推定
実際は  8/3 ≒ 2.6666666666667

MC法は  I = 2.666462964444

## サンプリングに偏りを持たせる
日本語pdf資料の方がちょっと良いコードになっている。ゼロ除算の回避を入れている

0から2にむけて線形に増加するサンプリングを考えたときの結果は

I = 2.666772599164

一様サンプリングより若干近い値が得られた？