using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Windows.Forms;

namespace TriviaClientGUI
{
    // using https://app.quicktype.io is usefull

    public class StatusResponse { public int Status { get; set; } }
    public class Statistics { public int Status { get; set; } public HighScore[] HighScores { get; set; } public UserStatistics UserStatistics { get; set; } }
    public class HighScore { public string Name { get; set; } public int NumOfCorrectAnswers { get; set; } }
    public class UserStatistics { public float AverageAnswerTime { get; set; } public int CorrectAnswers { get; set; } public int PlayerGames { get; set; } public int TotalAnswers { get; set; } }
    public class GetRooms { public Room[] Rooms { get; set; } public int Status { get; set; } }
    public class Room { public string CreatedBy { get; set; } public string RoomName { get; set; } public int RoomId { get; set; } }
    public class GetPlayersInRoom { public Player[] PlayersInRoom { get; set; } }
    public class Player { public string PlayerName { get; set; } }
    public class CreateRoom { public int Status { get; set; } public int RoomId { get; set; } }

    class Tools
    {
        static NetworkStream clientStream;

        static public string SendPayload(char code, string payload)
        {
            if (clientStream == null) // connect only if not already connected
            {
                try
                {
                    TcpClient client = new TcpClient();
                    IPEndPoint serverEndPoint = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 1234);
                    client.Connect(serverEndPoint);
                    clientStream = client.GetStream();
                }
                catch (Exception)
                {
                    clientStream = null;
                    MessageBox.Show("The server is dead", "Error Detected");
                    return "server is dead";
                }
            }
            string deserializeBuffer;
            try
            {
                payload = code + payload.Length.ToString("D5") + payload;
                byte[] buffer = new ASCIIEncoding().GetBytes(payload);
                clientStream.Write(buffer, 0, buffer.Length);
                clientStream.Flush();
                buffer = new byte[4096];
                clientStream.Read(buffer, 0, 4096);
                deserializeBuffer = Encoding.UTF8.GetString(buffer);
                deserializeBuffer = deserializeBuffer.Substring(5, Int32.Parse(deserializeBuffer.Substring(1, 4)) - 1);
            }
            catch(Exception)
            {
                clientStream = null;
                MessageBox.Show("The server has died, you have been loged out", "Error Detected");
                return "server has died";
            }
            return deserializeBuffer;
        }
    }
}
