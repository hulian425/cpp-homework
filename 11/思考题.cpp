#include <iostream>
#include <string>
#include <cmath>
using namespace std;




string sample1 = "七里香窗外的麻雀在电线杆上多嘴你说这一句很有夏天的感觉手中的铅笔在纸上来来回回我用几行字形容你是我的谁秋刀鱼的滋味猫跟你都想了解初恋的香味就这样被我们寻回那温暖的阳光像刚摘的新鲜草莓你说你舍不得吃掉这一种感觉雨下整夜我的爱溢出就像雨水院子落叶跟我的思念厚厚一叠几句是非也无法将我的热情冷却你出现在我诗的每一页雨下整夜我的爱溢出就像雨水窗台蝴蝶像诗里纷飞的美丽章节我接着写把永远爱你写进诗的结尾你是我唯一想要的了解那饱满的稻穗幸福了这个季节而你的脸颊像田里熟透的蕃茄.你突然对我说七里香的名字很美我此刻却只想亲吻你倔强的嘴星晴乘着风游荡在蓝天边一片云掉落在我面前捏成你的形状随风跟着我一口一口吃掉忧愁载着你彷佛载着阳光不管到哪里,都是晴天.蝴蝶自在飞.花也布满天.一朵一朵,因你而香.试图让夕阳飞翔.带领你我环绕大自然.迎着风,开始共度每一天.手牵手,一步两步三步四步,望着天.看星星,一颗两颗三颗四颗,连成线.背对背,默默许下心愿.看远方的星,是否听得见.";
	
string sample2 = "阴天在不开灯的房间,当所有思绪都一点一点沉淀.爱情究竟是精神鸦片, 还是世纪末的无聊消遣.香烟氲成一滩光圈, 和他的照片就摆在手边, 傻傻两个人笑的多甜.开始总是分分钟都妙不可言, 谁都以为热情它永不会减.除了激情褪去后的那一点点倦, 也许像谁说过的贪得无厌.活该应了谁说过的不知检点, 总之那几年感性赢了理性的那一面.阴天在不开灯的房间, 当所有思绪都一点一点沉淀.爱恨情欲里的疑点盲点, 呼之欲出那么明显.女孩通通让到一边, 这歌里的细微末节就算都体验, 若想真明白真要好几年.回想那一天喧闹的喜宴, 耳边响起的究竟是序曲或完结篇.感情不就是你情我愿, 最好爱恨扯平两不相欠.感情说穿了一人挣脱的一人去捡, 男人大可不必百口莫辩.女人实在无须楚楚可怜, 总之那几年你们两个没有缘.阴天在不开灯的房间, 当所有思绪都一点一点沉淀.爱情究竟是精神鸦片, 还是世纪末的无聊消遣.香烟氲成一滩光圈, 和他的照片就摆在手边.傻傻两个人笑的多甜, 傻傻两个人笑的多甜.还是会寂寞 早已忘了想你的滋味是什么.因为每分每秒都被你占据在心中.你的一举一动牵扯在我生活的隙缝,谁能告诉我离开你的我会有多自由,也曾想过躲进别人温暖的怀中.可是这么一来就一点意义也没有.我的高尚情操一直不断提醒著我.离开你的我不论过多久还是会寂寞,别对我小心翼翼.别让我看轻你.跟著我勇敢的走下去.别劝我回心转意.这不是廉价的爱情.看著我对我说真爱我.也曾想过躲进别人温暖的怀中.可是这么一来就一点意义也没有.我的高尚情操一直不断提醒著我.离开你的我不论过多久还是会寂寞,别对我小心翼翼.别让我看轻你.跟著我勇敢的走下去.别劝我回心转意.这不是廉价的爱情.看著我对我说真爱我.也曾想过躲进别人温暖的怀中.可是这么一来就一点意义也没有.我的高尚情操一直不断提醒著我.离开你的我不论过多久还是会寂寞.";


bool judge(string s) {
	double c1 = 0, c2 = 0;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < sample1.size(); j++)
		{
			if (sample1[j] == s[i] && sample1[j + 1] == s[i + 1] &&
				j + 1 < sample1.size() && i + 1 < s.size())
			{
				int ii = i;
				int jj = j;
				int q = 0;
				while (sample1[jj] == s[ii] && sample1[jj + 1] == s[ii + 1] &&
					jj + 1 < sample1.size() && ii + 1 < s.size() && ii < s.size() &&
					jj < sample1.size())
				{
					q++;
					ii += 2;
					jj += 2;
				}

				if (q == 1)
				{
					c1 += 0.3;
				}
				else c1 += double(pow(2, q));
			}
		}
	}

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < sample2.size(); j++)
		{
			if (sample2[j] == s[i] && sample2[j + 1] == s[i + 1] &&
				j + 1 < sample2.size() && i + 1 < s.size())
			{
				int ii = i;
				int jj = j;
				int q = 0;
				while (sample2[jj] == s[ii] && sample2[jj + 1] == s[ii + 1] &&
					jj + 1 < sample2.size() && ii + 1 < s.size() && ii < s.size() &&
					jj < sample2.size())
				{
					q++;
					ii += 2;
					jj += 2;
				}

				if (q == 1)
				{
					c2 +=0.3;
				}
				else c2 += double(pow(2, q));
			}
		}
	}
	cout << "快乐分 "<<c1 <<endl << "伤心分 "<< c2 << endl;
	return c1 > c2;
}

int main() {
	string a;
	cout << "请输入歌词" << endl;
	cin >> a;
	judge(a) ? cout << "快乐的歌\n" : cout << "伤心的歌\n";
	return 0;
}

