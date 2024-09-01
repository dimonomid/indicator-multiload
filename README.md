# indicator-multiload working properly in Linux Mint 22 MATE and Linux Mint 21 MATE

## General info

This indicator, developed by [Michael Hofmann](https://github.com/mh21), is a
fantastic app; I've been using it since year 2012-ish and it became totally
indispensable for me. It does exactly what it needs to, and does it well.

Unfortunately though, linux GUI is still kind of a wild west, and what works
in one DE, might not work in another DE, and the tray icons is one of the
especially messy areas. So as it happened, indicator-multiload 0.3 was working
fine in Linux Mint MATE, and then in the new version 0.4, something broke and
it started flickering. It worked fine in Cinnamon and Unity, but not in MATE.
There are multiple reports of this bug, e.g.  here's a couple of them (there
are more though):

- https://askubuntu.com/questions/1409960/app-indicator-top-bar-flickering-22-04
- https://bugs.launchpad.net/ubuntu/+source/indicator-multiload/+bug/2003195

So for a while, to address this issue for myself, I've been just building the
old version 0.3 from sources, and it was working fine.

And then somewhere around 2021-ish, something else happened: the old
`appindicator3` library, which `indicator-multiload` depends on, [got
deprecated in favor of the new
ayatana-appindicator3](https://github.com/AyatanaIndicators/libayatana-appindicator/issues/30),
and some more patching was needed to keep 0.3 working. Luckily, it was a
simple drop-in replacement, and this repo contains the patch.

This issue was not isolated to Linux Mint MATE only: Ubuntu MATE was also
affected at some point, although when I tested a few distros in Sep 2024,
the only problematic ones were Linux Mint MATE and Xfce. This repo only helps
with MATE though; Linux Mint Xfce is still affected. Some test results:

- Linux Mint 22 Cinnamon: works with stock `indicator-multiload`
- Linux Mint 22 MATE: stock `indicator-multiload` does not work, this repo
  works
- Linux Mint 22 Xfce: does not work (neither the stock one, nor this repo)
- Linux Mint 21.3 MATE: stock `indicator-multiload` does not work, this repo
  works
- Ubuntu 24.04.1 Unity, MATE and Xfce all work with the stock
  `indicator-multiload`
- Ubuntu 22.04.1 MATE works with stock `indicator-multiload`

So really, in 2024, this repo is only useful for Linux Mint MATE. Still, here
it is, in case it's useful to someone.

## Usage

### Using prebuilt deb package

Just use the `indicator-multiload-my_0.3-1_amd64.deb` from the releases here
on Github.

### Building from source

Install build prerequisites:

```
$ sudo apt install libgtk-3-dev libayatana-appindicator3-dev libgtop2-dev intltool
```

Configure:

```
$ ./configure
```

Bump timestamp of `indicator_multiload_vala.stamp` to prevent building C code
from Vala sources (at least because Vala sources in this repo are incompatible
with the modern-day Vala compiler: tested it on 0.56.16 and it didn't work).
Since this repo already includes the C code, we can simply use that.

```
$ touch ./src/indicator_multiload_vala.stamp
```

Build:

```
$ make
```

Install:

```
$ sudo make install
```
