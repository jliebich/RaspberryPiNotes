# Tag 1

Distros liefern Security fixes. Bei Yocto ist das nicht unbedingt der Fall.

BMW verwendet Intel und Yocto üblich ist ber eher ARM.

Yocto: Master branch besser nicht verwenden, sondern stable

Poky ist die Referenzimpelementierung von Yocto.

bitBake ist task scheduler (sowas wie make): Programmierbar Phython oder shell script

Mega Manual: https://www.yoctoproject.org/docs/latest/mega-manual/mega-manual.html
BitbakeManual: https://www.yoctoproject.org/docs/1.6/bitbake-user-manual/bitbake-user-manual.html

Möglichst gleiche Releases verwenden (Yocto Release sollte zu Layer-Release passen)
https://wiki.yoctoproject.org/wiki/Releases

.bb ist Dateiendung für recipes
.bbappend ist Dateiendung für Änderungen an bestehenden Rezepten

include vs. require: require bricht ab, include läuft weiter

In local.conf Änderungen sind gefährlich, da sie die höchste Prio hatben.

meta-yocto ist veraltet -> neu meta-poky

Anforderungen an Hardware:
64 bit Ubutntu 8+ core >1TByte

bitbake aus poky verwenden!

# Tag 2

DL_DIR: Empfehlung: umbiegen - nicht Projektspezifisch machen

