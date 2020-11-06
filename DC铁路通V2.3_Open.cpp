/*DC铁路 V2.3 自由软件版
**版本：Linux
**作者：锟斤拷xs
**自由软件，遵守GPL-3.0协议
**自V3.0开始，代码全部重构
**由于当时为初学水平，且设计不成熟，所以有许多问题请您谅解
**请注意软件注释不能很好表达内容或有表述错误，请注意
**开发目的为为一个铁路向Minecraft服务器玩家提供便捷的查询方法
**Github页面：https://github.com/kunjinkao-xs/DCRH_Open/
**若要修改后分发，请您遵守GPL-3.0协议并标明作者和Github页面*/

#include<iostream>
#include<cctype>
using namespace std;
//前置声明的子函数
int cal_train();
//**********此为列车数据信息部分**********
//***软件数据定义***
string app_ver = "2.3 自由版";
string app_content_ver = "20200724V2节选示例";//程序内容版本
string app_sys ="Linux";//程序平台
bool debug = 1;//开发模式，是0/否1
int total_train = cal_train();//定义总收录列车信息数目
int D_train,Z_train,T_train,K_train;//定义各自
int total_station = 0;//定义总收录车站信息数目
//***其他数组定义***

//***列车停站数组定义***
//最后更新：20200704-V2 开源后节选部分
string TLZ[][30]={
    {"D7","1","主城南","润林东","主城南","8:04","三界北","8:36/43","僻湖","10:02/09","钓鱼湾","10:44/50","滴水原","12:39/45","润林东","13:27"},
    {"D8","1","润林东","主城南","润林东","13:39","滴水原","14:21/27","钓鱼湾","16:16/22","僻湖","16:58/17:04","三界北","18:23/30","主城南","19:04"},
    {"D101","1","主城东","东篱","主城东","10:41","洛南村","12:40/46","东篱","14:03"},
    {"D102","1","东篱","主城东","东篱","7:02","洛南村","8:18/24","主城东","10:23"},
    {"D103","1","主城东","东篱","主城东","18:41","洛南村","20:10/16","东篱","21:33"},
    {"D104","1","东篱","主城东","东篱","14:32","洛南村","15:48/54","主城东","17:53"},
    {"D109","1","主城南","沙城","主城南","5:59","三界北","6:31/38","僻湖","7:58/8:04","彩云村","9:37/43","平阳","10:09/15","沙城","10:56"},
    {"D110","1","沙城","主城南","沙城","5:57","平阳","6:39/46","彩云村","7:11/17","僻湖","8:50/56","三界北","10:15/21","主城南","10:56"},
    {"D111","1","主城南","沙城","主城南","8:59","三界北","9:31/38","僻湖","10:58/8:04","彩云村","12:37/43","平阳","13:09/15","沙城","13:56"},
    {"D112","1","沙城","主城南","沙城","9:34","平阳","10:16/22","彩云村","10:47/53","僻湖","12:26/32","三界北","13:51/58","主城南","14:31"},
    {"D113","1","主城南","沙城","主城南","11:59","三界北","12:31/38","僻湖","13:58/8:04","彩云村","15:37/43","平阳","16:09/15","沙城","16:56"},
    {"D114","1","沙城","主城南","沙城","12:34","平阳","13:16/22","彩云村","13:47/53","僻湖","15:26/32","三界北","16:51/58","主城南","17:31"},
    {"D115","1","主城南","沙城","主城南","13:59","三界北","14:31/38","僻湖","15:58/8:04","彩云村","17:37/43","平阳","18:09/15","沙城","18:56"},
    {"D116","1","沙城","主城南","沙城","14:34","平阳","15:16/22","彩云村","15:47/53","僻湖","17:26/32","三界北","18:51/58","主城南","19:31"},
    {"Z1","1","主城南","终南山","主城南","8:17","终南山","13:17"},
    {"Z2","1","终南山","主城南","终南山","13:39","主城南","18:33"},
    {"Z61/4","1","僻湖","终南山","僻湖","12:18","矢口京西","14:39/45","界南北","17:15/21","终南山","18:45"},
    {"Z62/3","1","终南山","僻湖","终南山","12:02","界南北","13:25/32","矢口京西","16:02/08","僻湖","18:31"},
    };
//***车站数组定义***
//**********此为程序执行部分**********
//全局变量

//函数前置声明

//子函数
//功能退出
void pause()
{
    pausest:
    string opt;
    cout<<"[DC铁路通]您离开了功能，请选择下一步操作："<<endl<<"若进主菜单请输入c"<<endl<<"若退出程序请输入q"<<endl<<"[c/q]: ";
    cin>>opt;
    if(opt=="c")//继续函数
    {
        system("clear");//清屏[版本不同]
    }
    else if(opt=="q")//退出程序
    {
        system("clear");//清屏[版本不同]
        cout<<"[DC铁路通]您已退出DC铁路通，欢迎您下次使用！"<<endl;
        exit(0);
    }
    else if(opt=="rby")//debug-重新编译运行
    {
        system("clear");//清屏[版本不同]
        cout<<"[DC铁路通]您已退出DC铁路通，正准备重新编译(Linux GCC)"<<endl;
        system("g++ DCRailHelper.cpp -o DCRailHelper && ./DCRailHelper");
        exit(0);
    }
    else if(opt=="debug")//debug-显示debug信息
    {
        system("clear");//清屏[版本不同]
        cout<<"[DC铁路通]开发模式开启"<<endl;
        debug = 0;
    }
    else if(opt=="exitdebug")//debug-显示debug信息
    {
        system("clear");//清屏[版本不同]
        cout<<"[DC铁路通]开发模式关闭"<<endl;
        debug = 1;
    }
    else
    {
        cout<<"[DC铁路通]请检查您的输入内容"<<endl;
        goto pausest;
    }
}

//耗时计算函数-只返回时间

//开行频率函数
string frequncy(int i)
{
    if(TLZ[i][1]=="1")
    {
        return("每日开行");
    }
    else if(TLZ[i][1]=="2")
    {
        return("高峰开行");
    }
    else if(TLZ[i][1]=="3")
    {
        return("图定临客");
    }
    else if(TLZ[i][1]=="4")
    {
        return("临时停运");
    }
    else
    {
        return("其他模式");
    }

}

//站到站车次查询
void zzcx(string f,string t)
{
    system("clear");//清屏[版本不同]
    cout<<"[DC铁路通]正在查询从 "<<f<<" 到 "<<t<<" 的可用旅客列车"<<endl;
    /*查找部分:
    **逻辑：从数组的 TLZ[4][](第五个)查起，选出找到发站的;再在向后查找有没有到站
    **使用for+if*/
   if(f==t)
   {
       cout<<"[DC铁路通]起点和终点站相同，若要查询车站所有列车请您使用“5.查找车站所有列车”"<<endl;
   }
   else
   {
        int count=1,find=1;//查找次数
        int i=0;//数字定义
        bool afind= 1;//返回是否找到的变量
        while(find<=total_train)//多次查找直到找完所有的数据
        {
            int j,k;//定义k变量
            int mjk;//定义最大jk值
            do{
            if(debug == 0){cout<<"[开发模式]已经进入查找while语句，次数为"<<find<<endl;}
            j=4,k=4;//重置jk变量
            mjk=0;//重置最大jk值
            //计算jk最大值
            for(;TLZ[i][mjk]!="";mjk++){}
            mjk = mjk-1;//数组从0开始
            if(debug == 0){cout<<"[开发模式]jk最大值为"<<mjk<<endl;}
                //进行查找
                if(debug == 0){cout<<"[开发模式]进入while值为i="<<i<<" j="<<j<<" k="<<k<<" mjk:"<<mjk<<endl;}
                for(;TLZ[i][j]!=f&&j<mjk;j+=2){if(debug == 0){cout<<"[开发模式]for-1语句循环中,i="<<i<<" j="<<j<<" k="<<k<<endl;}}//找有没有发站
                for(k=j+2;TLZ[i][k]!=t&&k<mjk;k=k+2){if(debug == 0){cout<<"[开发模式]for-2语句循环中,i="<<i<<" j="<<j<<" k="<<k<<endl;}}//找有没有到站
                if(j>mjk||k>mjk)
                {
                    i++;//进行下一个车次的查找
                    find++;
                }
            }while((j>mjk||k>mjk)&&find<=total_train);
            if(debug == 0){cout<<"[开发模式]第"<<find<<"轮while运算结束，目前i="<<i<<" j="<<j<<" k="<<k<<endl;}
                //显示车站类型
                //出发站是否为始发站
                string f_s,t_e;
                if (f==TLZ[i][2])
                {
                    f_s="始";
                }
                else
                {
                    f_s="过";
                }
                //到达站是否为终到站
                if (t==TLZ[i][3])
                {
                    t_e="终";
                }
                else
                {
                    t_e="过";
                }
                if (find<=total_train)//防止范围外内容出现
                {
                    afind = 0;//已找到
                    cout<<count<<".  车次:"<<TLZ[i][0]<<"次   "<<f<<"("<<f_s<<")"<<" ——> "<<t<<"("<<t_e<<")"<<endl<<
                    "    出发站时刻： "<<TLZ[i][j+1]<<"   到达站时刻： "<<TLZ[i][k+1]<<endl;
                    cout<<"    开行情况: "<<frequncy(i);
                    if(f!=TLZ[i][2]||t!=TLZ[i][3])//非始发终到显示始发终到
                    {
                        cout<<"  #本车始发自 "<<TLZ[i][2]<<" 终到为 "<<TLZ[i][3];
                    }
                    else
                    {
                        cout<<"  #乘坐终到车时避免进入车辆段";
                    }
                }
            
            cout<<endl<<endl;
            i++;//进行下一个车次的查找
            count++;
            find++;
        }
        if(afind == 1)
        {
            cout<<"[DC铁路通]没有找到可用列车，请您检查您的车站和线路。可以试试聚落内的其他客运车站。"<<endl;
        }
   }
}
//车次信息查询
void zcxx(string train)
{
    system("clear");//清屏[版本不同]
    cout<<"[DC铁路通]您所查询的车次为："<<train<<"次"<<endl;
    int i;//查找次数
    for(i=0;TLZ[i][0]!=train&&i<total_train;i++){}//查找车次
    //显示信息
    if(debug == 0)//DEBUG提示
    {
        cout<<"[开发模式]查找到车次所用数组"<<i<<endl;
    }
    //写出车次信息
    if(i>=total_train)
    {
        cout<<"没有找到列车 "<<train<<"次,请您使用时刻表检查车次或确认内容版本是否过时"<<endl;
    }
    else
    {
        cout<<"开行情况: "<<frequncy(i)<<endl;
        int count=1;
        for(int j=4;j<30;j=j+2)//显示停站时刻
        {
            if(debug == 0)//DEBUG提示
            {
                cout<<"[开发模式]数组显示读取变量j="<<j<<endl;
            }
            if(TLZ[i][j] != "")//若内容不为空，显示
            {
            cout<<count<<".   停站："<<TLZ[i][j]<<"   时刻："<<TLZ[i][j+1]<<endl;//停站/停站+1即为时刻，下一次就j+2
            count++;//车站停靠序号自增
            }
        }
    }

}
//最近车站查询
string near(double pos_x,double pos_z)
{
    cout<<"无数据"<<endl;
    return("none");
    /*double station_x,station_z;
    string station_name;
    return(station_x,station_z,station_name);*/
}
//车站所有车次查询-改自站站查询
string staall(string sta)
{
   system("clear");//清屏[版本不同]
    cout<<"[DC铁路通]正在查询 "<<sta<<" 站的可用旅客列车"<<endl;
    /*查找部分:
    **逻辑：从数组的 TLZ[4][](第五个)查起，选出找到发站的;再在向后查找有没有到站
    **使用for+if*/
   /*查找车站所有车修改内容：
   **不需要查找到站
   **提示变更
   **要防止没时间的空车次错误出现*/
    int count=1,find=1;//查找次数
    int i=0;//数字定义
    bool afind= 1;//返回是否找到的变量
    while(find<=total_train)//多次查找直到找完所有的数据
    {
        int j,k;//定义k变量
        int mjk;//定义最大jk值
        do{
        if(debug == 0){cout<<"[开发模式]已经进入查找while语句，次数为"<<find<<endl;}
        j=4,k=4;//重置jk变量
        mjk=0;//重置最大jk值
        //计算jk最大值
        for(;TLZ[i][mjk]!="";mjk++){}
        mjk = mjk-1;//数组从0开始
        if(debug == 0){cout<<"[开发模式]jk最大值为"<<mjk<<endl;}
            //进行查找
            if(debug == 0){cout<<"[开发模式]进入while值为i="<<i<<" j="<<j<<" k="<<k<<" mjk:"<<mjk<<endl;}
            for(;TLZ[i][j]!=sta&&j<mjk;j+=2){if(debug == 0){cout<<"[开发模式]for-1语句循环中,i="<<i<<" j="<<j<<" k="<<k<<endl;}}//找有没有发站
            if(j>mjk||k>mjk)
            {
                i++;//进行下一个车次的查找
                find++;
            }
        }while((j>mjk||k>mjk)&&find<total_train);//修正了数组超出范围-BUGFIX20200724
        if(debug == 0){cout<<"[开发模式]第"<<find<<"轮while运算结束，目前i="<<i<<" j="<<j<<" k="<<k<<endl;}
        if(TLZ[i][5]=="")//防止空时刻车次出现-BU5GFIX200707
        {
            cout<<"";
        }
        else//正常车次
        {       
            if (find<total_train)//修正了数组超出范围-BUGFIX20200724
            {
                afind = 0;//已找到
                //车站经过/始发/终到不同类型提示
                if(sta==TLZ[i][2])
                {
                    cout<<count<<".  车次:"<<TLZ[i][0]<<"次   "<<TLZ[i][2]<<"(本站) ————> "<<TLZ[i][3]<<endl<<
                    "    本站始发时刻： "<<TLZ[i][j+1]<<"    开行情况: "<<frequncy(i)<<endl;
                }
                else if(sta==TLZ[i][3])
                {
                    cout<<count<<".  车次:"<<TLZ[i][0]<<"次   "<<TLZ[i][2]<<" ————> "<<TLZ[i][3]<<"(本站)"<<endl<<
                    "    终到本站时刻： "<<TLZ[i][j+1]<<"    开行情况: "<<frequncy(i)<<endl;
                }
                else
                {
                    cout<<count<<".  车次:"<<TLZ[i][0]<<"次   "<<TLZ[i][2]<<" ——"<<sta<<"——> "<<TLZ[i][3]<<endl<<
                    "    途径本站时刻： "<<TLZ[i][j+1]<<"    开行情况: "<<frequncy(i)<<endl;
                }
            }
        }
            
        cout<<endl;
        i++;//进行下一个车次的查找
        count++;
        find++;
    }
    if(afind == 1)
        {
            cout<<"[DC铁路通]没有找到可用列车，请您检查您的车站和线路。可以试试聚落内的其他客运车站。"<<endl;
        }
    return ("[DC铁路通]查询成功");
}
//自动计算有多少列车数目
int cal_train()
{
    Z_train = sizeof(TLZ)/sizeof(TLZ[0]);
    //T_train = sizeof(TLT)/sizeof(TLT[0]);
    int row = Z_train;//+T_train;
    return row;
}
//显示维护模式信息
string debug_echo()
{
    if(debug == 0)
    {
        return ("开发模式");
    }
    else if(debug == 1)
    {
        return("");
    }
    return("a");
}


//主函数
int main()
{
    if(app_sys=="Windows")//Windows系统下使用title命令弄标题
        {
            system("title DC铁路通Windows");
        }
    start:
    cout<<"[DC铁路通]欢迎使用DC铁路通APP For "<<app_sys<<endl<<"程序版本："<<app_ver<<" "<<debug_echo()<<endl<<"内容版本："<<app_content_ver<<endl;//软件基本信息
    cout<<"欢迎使用DC铁路应用程序，请选择您需要的功能："<<endl<<//菜单
    "1.站到站车次查询"<<endl<<
    "2.车次信息查询"<<endl<<
    "3.查询我最近的车站"<<endl<<
    "4.接续换乘建议"<<endl<<
    "5.查找车站所有列车"<<endl<<
    "9.退出程序"<<endl<<
    "0.关于软件"<<endl<<
    "例如，使用站到站车次查询应该输入1然后回车"<<endl<<
    "请输入功能序号:";
    //功能选择部分
    int opt;
    cin>>opt;
    switch(opt)
    {
        case 1:
        {
            system("clear");//清屏[版本不同]
            string from,to;//收集信息
            cout<<"[DC铁路通]请您输入必要信息来使我们为您查询"<<endl<<"[DC铁路通]请您务必输入正确车站名而非聚落名，若不知道请您善用“查询我最近的车站功能"<<endl<<"若退出返回主菜单请输入/back"<<endl<<"请输入出发站:";
            cin>>from;
            if (from == "/back")
            {
                cout<<"您选择回到主菜单"<<endl;
                break;
            }
            cout<<"请输入到达站：";
            cin>>to;
            cout<<"[DC铁路通]正在调用功能"<<endl;
            zzcx(from,to);//调用查询函数zzcx
            pause();
            break;
        }
        case 2:
        {
            system("clear");//清屏[版本不同]
            string train;//收集信息
            cout<<"[DC铁路通]请您输入一个可用的车次。"<<endl<<"注：需要变换上下行的车次请不要输入单车次，请输入如Z151/4而非Z151和Z154"<<endl<<"若退出返回主菜单请输入/back"<<endl<<"车次：";
            cin>>train;
            if (train == "/back")
            {
                cout<<"您选择回到主菜单"<<endl;
                pause();
                break;
            }
            zcxx(train);//调用查询函数zcxx
            pause();
            break;
        }
        case 3:
        {
            system("clear");//清屏[版本不同]
            double x,z;//收集信息
            cout<<"[DC铁路通]请您输入必要信息来使我们为您查询"<<endl<<"请输入x轴坐标:";
            cin>>x;
            cout<<"请输入z轴坐标：";
            cin>>z;
            near(x,z);
            pause();
            break;
        }
        case 4:
        {
            system("clear");//清屏[版本不同]
            cout<<"您可选择去往最近区域或全服枢纽，然后查找枢纽到您的目的车站或者另一个枢纽的车次。"<<"比如要从滴水原去往终南山，先查找滴水原-僻湖列车再查找僻湖-终南山列车即可"<<"具体建议可参考群文件列车时刻表"<<endl;
            pause();
            break;
        }
        case 5:
        {
            system("clear");//清屏[版本不同]
            string station;
            cout<<"[DC铁路通]欢迎使用车站列车查询，请您输入必要信息来使我们为您查询"<<endl<<"请您输入车站名：";
            cin>>station;
            staall(station);
            cout<<endl;
        }
        case 9:
        {
            pause();
            break;
        }
        case 0:
        {
            system("clear");//清屏[版本不同]
            cout<<"关于软件"<<endl<<
            "软件版本："<<app_ver<<endl<<
            "运行平台："<<app_sys<<endl<<
            "内容版本："<<app_content_ver<<endl<<
            "收录列车条数："<<total_train<<"条"<<"("<<D_train<<"/"<<Z_train<<"/"<<T_train<<"/"<<K_train<<")"<<endl<<
            "收录车站条数："<<total_station<<"条"<<endl<<
            "内容版本关系着列车时刻是否为最新时刻，请您务必注意内容版本是否最新"<<endl<<
            "软件作者：锟斤拷xs"<<endl<<
            "调试编译环境：gcc version 9.3.0 (Ubuntu 9.3.0-10ubuntu2)"<<endl<<
            "V2.3版本为自由软件，遵守GNU GPL-3.0协议"<<endl<<
            "Github地址：https://github.com/kunjinkao-xs/DCRH_Open/"<<endl;
            pause();
            break;
        }
        default:
        {cout<<"范围外的数字，请您检查并重新输入"<<endl;goto start;}
    }
    goto start;//退回主菜单
    
}