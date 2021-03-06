This project is archived and won't be maintained anymore. The authors will be devoted to the new version [PhysIKA](https://github.com/PhysikaTeam/PhysIKA).

=============================================================

**Physika**

Physika is a versatile C/C++ physics library. It was started as a personal project of [Fei Zhu](http://feizhu.github.io), then joined by four other students ([Sheng Yang](https://github.com/Vovery), [Tianxiang Zhang](https://github.com/TianxiangZhang), [Wei Chen](https://github.com/suitmyself), [Liyou Xu](https://github.com/MikeXuPku)) at the Graphics Lab of Peking University. Since July 2015, Physika is separately developed by Fei and the students at PKU. This repository is Fei's personal version mantained by himself, while the PKU version of Physika is maintained by the [PhysikaTeam](https://github.com/PhysikaTeam) at PKU led by  [Wei Chen](https://github.com/suitmyself).

@Last update of this file:
Fei Zhu, 12/24/2016

=============================================================

**Build Requirements:**

*Build Tool*: Scons

*Platforms*: Windows, Linux, MacOS

*Compiler*: GNU G++, MSVC

=============================================================

**Code Structure:**

*Documentation*: Documentations related to this project, including coding style and development plans.

*Public_Library*: Public API of Physika.

- *include*: Header files generated by Physika after compilation. Any project built on Physika simply needs to include files in this directory.
	
- *lib*: Binary files generated by Physika after compilation.
	
*Physika_Src*: Source code of Physika, including 3rd party libraries that Physika uses. After compilation, header files and binary libraries would be copied to the 2 directories in *Public_Library* directory.

*Projects*: Projects built on Physika. Generally they simply need to include necessary header files and link corresponding binaries of Physika.
