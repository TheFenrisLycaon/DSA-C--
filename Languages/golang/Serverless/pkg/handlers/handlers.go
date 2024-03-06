package handlers

import (
	"net/http"

	"github.com/TheFenrisLycaon/Serverless/pkg/user"
	"github.com/aws/aws-lambda-go/events"
	"github.com/aws/aws-sdk-go/service/dynamodb/dynamodbiface"
)

var ErrorMethodNotAllowed = "Method Not Allowed"

type ErrorBody struct {
	ErrorMsg *string `json:"error,omitempty"`
}

func GetUser(req events.APIGatewayProxyRequest, tableName string, dynaclient dynamodbiface.DynamoDBAPI) (
	*events.APIGatewayProxyResponse, error
	) {
	email := req.QueryStringParameters["email"]
	if len(email) > 0 {
		res, err := user.FetchUser(email, tableName, dynaclient)

		if err != nil {
			return apiResponse(http.StatusBadRequest, ErrorBody{aws.String(err.Error())})
		}
	}

	res, err := user.FetchUsers(tableName, dynaclient)
	if err != nil {
		return apiResponse(http.StatusBadRequest, ErrorBody{aws.String(err.Error())})
	}

	return apiResponse(http.StatusOK, res)

}


func UpdateUser(req events.APIGatewayProxyRequest, tableName string, dynaclient dynamodbiface.DynamoDBAPI) (
	*events.APIGatewayProxyResponse, error
) {

}


func CreateUser(req events.APIGatewayProxyRequest, tableName string, dynaclient dynamodbiface.DynamoDBAPI) (
*events.APIGatewayProxyResponse, error
) {

}


func DeleteUser() {

}


func UnhandledMethod() (*events.APIGatewayProxyResponse, error) {
	return apiResponse(http.StatusMethodNotAllowed, ErrorMethodNotAllowed)
}
